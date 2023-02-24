#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <map>
#include <regex>

class IParcer
{
public:
	
	virtual	~IParcer() {} 
	virtual void InputOpenIniNameFile() = 0;
	virtual void read() = 0;
	virtual std::string get_value(const std::string& section, const std::string& key) const = 0;
	virtual std::map<std::string, std::map<std::string, std::string>> get_data() const = 0;

};


