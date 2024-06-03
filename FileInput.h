#pragma once
#include <fstream>//Библеотека ввода и вывода из фаила
#include <iostream>//Библеотека ввода и вывода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила
#include <vector>//Подключение библеотеки вектора
#include <string>//Библеотека строк
#include "CheckException.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
std::vector<std::vector<int>> FileDataInput();//Файловый ввод