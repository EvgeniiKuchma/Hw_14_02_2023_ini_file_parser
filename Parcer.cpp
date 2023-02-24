#include "Parcer.h"

void Parcer::InputOpenIniNameFile() {

while(!file.is_open()){	
	std::cout << "Please enter name file : ";
	getline(std::cin, name);
	if (!name.rfind(".ini")) {
		file.open(name, std::ios::in);
		if (file.is_open()) {
			std::cout << "\nFile opening!\n\n";
			break;
		}
			else {
				std::cout << "\nFile opening error, please try again\n\n";
			}
	}
	else{
		std::cout << "\nThe file entered is not an ini file, please try again;\n\n";
	}
	std::cin.clear();			
}

file.close();
}