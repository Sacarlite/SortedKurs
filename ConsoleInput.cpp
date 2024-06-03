#include "ConsoleInput.h"
/*Функция ввода матрицы с консоли*/
std::vector<std::vector<int>> ConsoleInput()
{
	std::vector<std::vector<int>> matrix;//Объявление матрицы
	std::cout << "Введите размерность матрицы n(кол-во строк)Xm(кол-во столбцов). Учитывайте что для работы алгоритма кол-во строк должно быть не меньше 2х." << std::endl;
	std::cout << "Введите количество строк n=";
	int n = GetPositiveIntMoreThen1();//Ввод переменной строк больше 1
	std::cout << "Введите количество столбцов m=";
	int m = GetPositiveIntMoreThen0();//Ввод переменной столбцов больше 0
	for (int i = 0; i < n; i++)//Перебор по строкам
	{
		std::vector<int> row;//Объявление вектора строки
		for (int j = 0; j < m; j++) {//Перебор по столбцам

			std::cout << "matrix[" << i + 1 << "][" << j + 1 << "] = " << std::endl;
			row.push_back(GetInt());//Заполнение элемента строки и добавление его в конец вектора
			std::cout << "" << std::endl;
		}
		matrix.push_back(row);//Добавление строки в конец вектора
	}
	return matrix;
}
