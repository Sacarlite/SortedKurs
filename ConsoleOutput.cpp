#include "ConsoleOutput.h"
/*Вывод матрицы на консоль*/
void MatrixOutput(std::vector<std::vector<int>> intVec)
{
	for (int i = 0; i < intVec.size(); ++i)//Перебор матрицы по строкам
	{
		for (int j = 0; j < intVec[i].size(); ++j)//Перебор матрицы по столбцам
			std::cout << std::setw(12) << intVec[i][j] << " ";
		std::cout << std::endl;
	}
}
/*Вывод информации о сортировках на консоль*/
void SortInfoOutput(std::vector<std::shared_ptr<ISort>> infoVec)
{
	const int INDENT = 26;//Колличество символов в информационной строке
	for (int i = 0; i < infoVec.size(); ++i)
	{
		
		std::cout << "Название метода сортировки: " << infoVec[i]->GetName() << std::endl;
		std::cout << "Колличество сравнений: " << infoVec[i]->GetComparisonCounter() << std::endl;
		std::cout << "Колличество перестановок: " << infoVec[i]->GetPermutationCounter() << std::endl;
		std::cout << "Результирующая матрица: " << std::endl;
		MatrixOutput(infoVec[i]->GetMatrix());
		std::cout << std::endl;
	}
	std::cout << "Сравнительная таблица: " << std::endl;
	int largestNumPermutations = GetLargestNumPermutations(infoVec);//Получение самого большого числа перестановок
	int largestNumComparison = GetLargestNumComparison(infoVec);//Получение самого большого числа сравнений
	std::cout << "Метод" << std::setw(INDENT - 5 + largestNumPermutations) << std::right <<"Перестановки" << std::setw(largestNumComparison+10) << "Сравнения" << std::endl;
	for (int i = 0; i < infoVec.size(); ++i)
	{
		std::string name= infoVec[i]->GetName();
		int indent = INDENT - static_cast<int>(name.length());
		std::cout << name << std::setw(indent + largestNumPermutations) << infoVec[i]->GetPermutationCounter() << std::setw(largestNumComparison+10) << infoVec[i]->GetComparisonCounter() << std::endl;
	}
}
