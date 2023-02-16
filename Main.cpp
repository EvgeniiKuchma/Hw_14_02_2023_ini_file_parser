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