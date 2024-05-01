#pragma once
#include <string>

class CheckException
{
public:
	CheckException(std::string message) : message{ message } {}
	std::string GetMessage() const { return message; }
private:
	std::string message;
};