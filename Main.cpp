#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "IParcer.h"
#include "Parcer.h"

int main() {
	std::shared_ptr <IParcer> parc = std::make_shared<Parcer>();
	parc->InputOpeningNameFile();

	

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class IniFile {
public:
    virtual ~IniFile() {}

    virtual void read() = 0;

    virtual std::string get_value(const std::string& section, const std::string& key) const = 0;

    virtual std::map<std::string, std::map<std::string, std::string>> get_data() const = 0;
};

class IniFileImpl : public IniFile {
public:
    IniFileImpl(const std::string& file_path) : file_path_(file_path) {}

    void read() override {
        std::ifstream input_file(file_path_);
        if (!input_file.is_open()) {
            throw std::runtime_error("Error opening file: " + file_path_);
        }

        std::string line;
        std::string current_section;

        while (std::getline(input_file, line)) {
            // Remove leading and trailing whitespace
            line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");

            // Ignore comments and blank lines
            if (line.empty() || line[0] == ';' || line[0] == '#') {
                continue;
            }

            // Check for section header
            if (line[0] == '[' && line.back() == ']') {
                current_section = line.substr(1, line.length() - 2);
            }
            else {
                // Split the line into key-value pairs
                size_t equals_pos = line.find('=');
                if (equals_pos == std::string::npos) {
                    throw std::runtime_error("Invalid line: " + line);
                }
                std::string key = line.substr(0, equals_pos);
                std::string value = line.substr(equals_pos + 1);
                // Add the key-value pair to the map
                data_[current_section][key] = value;
            }
        }
    }

    std::string get_value(const std::string& section, const std::string& key) const override {
        if (data_.count(section) == 0 || data_.at(section).count(key) == 0) {
            throw std::runtime_error("Section or key not found");
        }
        return data_.at(section).at(key);
    }

    std::map<std::string, std::map<std::string, std::string>> get_data() const override {
        return data_;
    }

private:
    std::string file_path_;
    std::map<std::string, std::map<std::string, std::string>> data_;
};

int main() {
    IniFile* ini_file = new IniFileImpl("example.ini");

    ini_file->read();
    std::map<std::string, std::map<std::string, std::string>> ini_data = ini_file->get_data();

    for (const auto& section : ini_data) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (const auto& key_value : section.second) {
            std::cout << key_value.first << " = " << key_value.second << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Value of 'key1' in section 'section1': " << ini_file->get_value("section1", "key1") << std::endl;

    delete ini_file;

    return 0;
}