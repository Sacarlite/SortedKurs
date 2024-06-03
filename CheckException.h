#pragma once
#include <string>
/*Класс ошибок пользовательского ввода*/
class CheckException
{
public:
	CheckException(std::string message) : message{ message } {}//Конструктор класса ошибок пользовательского ввода
	std::string GetMessage() const { return message; }//Возврат сообщения
private:
	std::string message;//Поле сообщения
};