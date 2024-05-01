#include "RandomInput.h"
std::vector<std::vector<int>> RandomDataInput()
{
	const int lower_bound = 0;
	const int higher_bound = 100;
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<std::vector<int>> matrix;
	std::cout << "Введите размерность матрицы nXm. Минимальный размер матрицы 2x2" << std::endl;
	std::cout << "Введите n=";
	int n = GetPositiveIntMoreThen1();
	std::cout << "Введите m=";
	int m = GetPositiveIntMoreThen1();
	for (int i = 0; i < n; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < m; j++) {
			row.push_back(lower_bound + rand() % higher_bound + 1);
		}
		matrix.push_back(row);
	}
	return matrix;
}
