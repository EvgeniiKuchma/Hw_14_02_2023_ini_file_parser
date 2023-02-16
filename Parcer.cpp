#include "Parcer.h"

void Parcer::InputOpeningNameFile() 
{
	std::fstream file;
	std::string name;
	std::cout << "Please enter name file : ";
	getline(std::cin, name);
	file.open(name, std::ios::in | std::ios::out);
	std::cin.clear();
	while (std::cin.get() != '\n');
	if (file.is_open())
		std::cout << "File opening!\n";
	else
		std::cout << "File opening error\n";
	file.close();

}