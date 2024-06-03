#pragma once
#include <vector>//Подключение библеотеки вектора
#include "ISort.h"//Подключение HeaderFile с сортировками
#include "Algoritm.h"//Подключение HeaderFile с алгоритмами
void InputDataFileOutput(std::vector<std::vector<int>> matrix);//Вывод исходных данных в файл
void OutDataFileOutput(std::vector<std::shared_ptr<ISort>> InfoVec, std::vector<std::vector<int>> matrix);//Вывод информации о сортировках в файл