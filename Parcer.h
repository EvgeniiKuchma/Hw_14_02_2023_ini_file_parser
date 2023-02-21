#pragma once

#include "IParcer.h"
class Parcer : public IParcer
{
public:
	void InputOpeningNameFile() override;
private:
	std::ifstream file;
	std::string name;
};

