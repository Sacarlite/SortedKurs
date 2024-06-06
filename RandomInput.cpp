#include "RandomInput.h"
std::vector<std::vector<int>> RandomDataInput()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int lower_bound = 0;
	int higher_bound = 0;
	std::vector<std::vector<int>> matrix;
	std::cout << "Введите размерность матрицы n X m." << std::endl;
	std::cout << "Введите количество строк n=";
	int n = GetPositiveIntMoreThen1();
	std::cout << "Введите количество столбцов m=";
	int m = GetPositiveIntMoreThen0();
	while (true) {
		std::cout << "В каком диапазоне вы хотите сгенерировать значения:" << std::endl;
		std::cout << "Введите нижнюю границу: ";
		lower_bound = GetInt();
		std::cout << "Введите верхнюю границу: ";
		higher_bound = GetInt();
		if (lower_bound >= higher_bound) {
			std::cout << "Ошибка при вводе диапазона. Повторите попытку." << std::endl;
			continue;
		}
		break;
	}
	for (int i = 0; i < n; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < m; j++) {
			row.push_back(rand() % (higher_bound - lower_bound + 1) + lower_bound);
		}
		matrix.push_back(row);
	}
	return matrix;
}
