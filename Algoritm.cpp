#include "Algoritm.h"
/*Фильтрация чётных значений из столбца*/
std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec,int j) {
	std::vector<int> evenVec;
	for (int i = 0; i < originalVec.size(); i++) {//Перебор значений вектора с координатой j
		if (originalVec[i][j] % 2 == 0) {//Проверка чётности
			evenVec.push_back(originalVec[i][j]);//Добавление в конец вектора
		}
	}
	return evenVec;
}
/*Возврат отсортированных значений в столбец с индексом j*/
//Значения возвращаются в порядке следования на исходные места
void ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>>& originalVec, int j) {

	int counter = 0;//Объявление счётчика
	for (int i = 0; i < originalVec.size(); i++) {//Перебор значений вектора с координатой j
		if (originalVec[i][j] % 2 == 0) {//Проверка чётности
			originalVec[i][j] = tmp_vec[counter];//Возврат отсортированного значения 
			counter++;//Прибавление счётчика
		}
	}
}
/*Функция выбора самого длинного числа перестановок*/
int GetLargestNumPermutations(std::vector<std::shared_ptr<ISort>> infoVec)
{
	int max = infoVec[0]->GetPermutationCounter();//Присваивание значению максимума первого значения
	for (int i = 1; i < infoVec.size(); ++i)//Перебор значений вектора с координатой
	{
		if (infoVec[i]->GetPermutationCounter() > max) {//Сравнивания значения с максимумом
			max = infoVec[i]->GetPermutationCounter();//Присваивание значения максимуму
		}
	}
	return static_cast<int>(std::to_string(max).length());//Преобразования числа в строку
}
/*Функция выбора самого длинного числа сравнений*/
int GetLargestNumComparison(std::vector<std::shared_ptr<ISort>> infoVec)
{
	int num = infoVec[0]->GetComparisonCounter();//Присваивание значению максимума первого значения
	for (int i = 1; i < infoVec.size(); ++i) // Перебор значений вектора с координатой
	{
		if (infoVec[i]->GetComparisonCounter() > num) {//Сравнивания значения с максимумом
			num = infoVec[i]->GetComparisonCounter();//Присваивание значения максимуму
		}
	}
	return static_cast<int>(std::to_string(num).length());//Преобразования числа в строку
}
