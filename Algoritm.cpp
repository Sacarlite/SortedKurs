#include "Algoritm.h"
void ConsoleInput(double** matrix, int n, int m)
{
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j < m; j++) {
			
			std::cout << "matrix[" << i+1 << "][" << j+1<< "]="  << std::endl;
			matrix[i][j] = GetDouble();
			std::cout << "" << std::endl;
		}
	}
}

void RandomInput(double** matrix, int n, int m)
{
	const int lower_bound=-25;
	const int higher_bound=50;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			matrix[i][j] = lower_bound + rand() % (higher_bound + 1) + rand() / (RAND_MAX + 1.0);
		}
	}

}

void copy(int** a, int** b, int n, int m)
{
		for (int j = 0; j < m; j++)
			if (a[n][j] % 2 == 0) {
				a[n][j] = b[n][j];
			}
}

void ConsoleOutput(double** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << std::setw(12) << matrix[i][j]<<" ";
		std::cout << std::endl;
	}
}



void ShowResult(std::vector<std::shared_ptr<result>>& sort, int n, int m)
{
	for (int index = 0; index < 5; index++) {
		std::cout << "Название метода сортировки: " << sort[index]->name << std::endl;
		std::cout << "Колличество сравнений: " << sort[index]->comparison_counter << std::endl;
		std::cout << "Колличество перестановок: " << sort[index]->permutation_counter << std::endl;
		std::cout << "Результирующая матрица: " << std::endl;
		double** showed_matrix = nullptr;
		showed_matrix = sort[index]->new_matrix;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << std::setw(12) << showed_matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Название метода сортировки       сравнения        перестановоки" << std::endl;
	for (int index = 0; index < 5; index++) {
		if (sort[index]->name == "SelectionSort" || sort[index]->name == "InsertionSort") {
			std::cout << sort[index]->name << "                        " << sort[index]->comparison_counter << "                  " << sort[index]->permutation_counter << std::endl;
		}
		else if(sort[index]->name == "BubbleSort") {
			std::cout << sort[index]->name << "                           " << sort[index]->comparison_counter << "                  " << sort[index]->permutation_counter << std::endl;
		}
		else {
			std::cout << sort[index]->name << "                             " << sort[index]->comparison_counter << "                 " << sort[index]->permutation_counter << std::endl;
		}
	}
	
}

