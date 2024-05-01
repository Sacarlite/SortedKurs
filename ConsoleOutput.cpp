#include "ConsoleOutput.h"
void MatrixOutput(std::vector<std::vector<int>> intVec)
{
	for (int i = 0; i < intVec.size(); ++i)
	{
		for (int j = 0; j < intVec[i].size(); ++j)
			std::cout << std::setw(12) << intVec[i][j] << " ";
		std::cout << std::endl;
	}
}
//TODO доделать форматированный вывод
void SortInfoOutput(std::vector<ISort*> infoVec)
{
	const int INDENT = 26;
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
	int largestNumPermutations = GetLargestNumPermutations(infoVec);
	int largestNumComparison = GetLargestNumComparison(infoVec);
	std::cout << "Метод" << std::setw(INDENT - 5 + largestNumPermutations) << std::right <<"Перестановки" << std::setw(largestNumComparison+10) << "Сравнения" << std::endl;
	for (int i = 0; i < infoVec.size(); ++i)
	{
		std::string name= infoVec[i]->GetName();
		int indent = INDENT - static_cast<int>(name.length());
		std::cout << name << std::setw(indent + largestNumPermutations) << infoVec[i]->GetPermutationCounter() << std::setw(largestNumComparison+10) << infoVec[i]->GetComparisonCounter() << std::endl;
	}
}
