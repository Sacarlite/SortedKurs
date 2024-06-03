#pragma once
#include <vector>//Подключение библеотеки вектора
#include <iostream>//Библеотека ввода и вывода
#include <string>//Библеотека строк
#include "ISort.h"//Подключение HeaderFile с сортировками
/*Функции использующиеся для фильтрации и возврата чётных значений стобца*/
std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec, int j);//Фильтрация чётных значений из столбца
void ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>>& originalVec, int j);//Возврат отсортированных значений в столбец с индексом j
/*Функции использующиеся для форматированного вывода*/
int GetLargestNumPermutations(std::vector<std::shared_ptr<ISort>> infoVec);//Функция выбора самого длинного числа перестановок
int GetLargestNumComparison(std::vector<std::shared_ptr<ISort>> infoVec);//Функция выбора самого длинного числа сравнений