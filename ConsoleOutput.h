#pragma once
#include <vector>//Подключение библеотеки вектора
#include <iostream>//Библеотека ввода и вывода
#include <string>//Библеотека строк
#include <iomanip>//Библеотека форматированного вывода
#include "ISort.h"//Подключение HeaderFile с сортировками
#include "Algoritm.h"//Подключение HeaderFile с алгоритмами

void MatrixOutput(std::vector<std::vector<int>> intVec);//Вывод матрицы на консоль
void SortInfoOutput(std::vector<std::shared_ptr<ISort>> infoVec);//Вывод информации о сортировках на консоль