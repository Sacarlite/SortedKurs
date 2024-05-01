#include "ConsoleInput.h"

std::vector<std::vector<int>> ConsoleInput()
{
	std::vector<std::vector<int>> matrix;
	std::cout << "Введите размерность матрицы n(кол-во строк)Xm(кол-во столбцов). Минимальный размер матрицы 2x2. Учитывайте что для работы алгоритма кол-во строк должно быть не меньше 2х." << std::endl;
	std::cout << "Введите n=";
	int n = GetPositiveIntMoreThen1();
	std::cout << "Введите m=";
	int m = GetPositiveIntMoreThen0();
	for (int i = 0; i < n; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < m; j++) {

			std::cout << "matrix[" << i + 1 << "][" << j + 1 << "] = " << std::endl;
			row.push_back(GetPositiveInt());
			std::cout << "" << std::endl;
		}
		matrix.push_back(row);
	}
	return matrix;
}
