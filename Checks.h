#pragma once
#include <iostream>//Библеотека ввода и вывода
#include "CheckException.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
int GetPositiveIntMoreThen1();//Функция ввода с консоли целого положительного значения больше 1
int GetPositiveIntMoreThen0();//Функция ввода с консоли целого положительного значения больше 0
int GetInt();//Функция ввода с консоли целого  значения
int GetChoise();//Функция ввода пользовательского выбора
int GetMenuChoise();//Функция ввода пользовательского выбора пункта меню
int CheckLineIMoreThen1(std::ifstream& file);//Функция ввода целочисленного значения из файла больше 1
int CheckLineIMoreThen0(std::ifstream& file);//Функция ввода целочисленного значения из файла больше 0
std::string CheckLineS(std::ifstream& file);//Функция ввода строки  из файла