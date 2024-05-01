#pragma once
#include <fstream>//Библеотека ввода и вывода из фаила
#include <iostream>//Библеотека ввода и вывода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила
#include <vector>
#include <string>
#include "CheckException.h"
#include "Checks.h"
std::vector<std::vector<int>> FileDataInput();