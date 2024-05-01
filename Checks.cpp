#include "Checks.h"
#include <iostream>
#include <fstream>
#include <string>
int GetPositiveIntMoreThen1()
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value > 1) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }

    }
}

int GetPositiveIntMoreThen0()
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }

    }
}

int GetPositiveInt()
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value >= 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }

    }
}

int GetChoise()
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if (value == 1 || value == 2) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}

int GetMenuChoise()
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if (value == 1 || value == 2||value==3) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}

int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        int temp_i = stoi(temp_v);//Преобразование строки в целочисленный тип
        if (temp_i <= 1)

        {
            throw  std::exception();//Выброс ошибки
        }
        else

            return temp_i;
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
}

std::string CheckLineS(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        return temp_v;

    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
}
