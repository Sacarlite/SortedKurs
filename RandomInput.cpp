#include "RandomInput.h"
std::vector<std::vector<int>> RandomDataInput()
{
	const int lower_bound = -100;
	const int higher_bound = 100;
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<std::vector<int>> matrix;
	std::cout << "¬ведите размерность матрицы n X m." << std::endl;
	std::cout << "¬ведите количество строк n=";
	int n = GetPositiveIntMoreThen1();
	std::cout << "¬ведите количество столбцов m=";
	int m = GetPositiveIntMoreThen0();
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
