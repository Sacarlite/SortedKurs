#pragma once
#include <iostream>//Библеотека ввода и вывода
#include <vector>//Библеотека подключения вектора
/*Базовый абстрактный класс ISort*/
class ISort
{
protected:
	int comparison_counter = 0;//Счётчик сравнений
	int permutation_counter = 0;//Счётчик перестановок
	std::vector<std::vector<int>> matrix;//Матрица
	std::string name;//Название сортировок
public:
	std::string GetName();//Получение названия сортировок
	int GetComparisonCounter();//Получение количества сравнений
	int GetPermutationCounter();//Получение количества перестановок 
	std::vector<std::vector<int>> GetMatrix();//Получение матрицы
	ISort(std::vector<std::vector<int>> matrix);//Конструктор класса
	virtual void Sort()=0;//Виртуальный метод сортировки
	~ISort() {//Деструктор
		if (!matrix.empty()) {//Если матрица не пуста
			matrix.clear();//Отчистка матрицы
		}
	};
};
/*Класс пузырьковой сортировки*/
class BubbleSort :public ISort {

public:
	BubbleSort(std::vector<std::vector<int>> matrix);//Конструктор класса пузырьковой сортировки
	void Sort() override;//Переопределения метода сортировки
};
/*Класс сортировки выбором*/
class SelectionSort :public ISort {
public:
	SelectionSort(std::vector<std::vector<int>> matrix);//Конструктор класса сортировки выбором
	void Sort() override;//Переопределения метода сортировки

};
/*Класс сортировки вставкой*/
class InsertionSort :public ISort {
public:
	InsertionSort(std::vector<std::vector<int>> matrix);//Конструктор класса сортировки вставкой
	void Sort() override;//Переопределения метода сортировки
};
/*Класс сортировки Шелла*/
class ShellSort :public ISort {
public:
	ShellSort(std::vector<std::vector<int>> matrix);//Конструктор класса сортировки Шелла
	void Sort() override;//Переопределения метода сортировки
};
/*Класс быстрой сортировки*/
class QuickSortMat :public ISort {
private:

	void QuickSort(std::vector<int>& arr, int start, int end);//Функция быстрой сортироыки
	int Partition(std::vector<int>& arr, int start, int end);//Функция определения опорного элемента
	void SwapElements(std::vector<int>& arr, int i, int j);
public:
	QuickSortMat(std::vector<std::vector<int>> matrix);//Конструктор класса быстрой сортировки 
	void Sort() override;//Переопределения метода сортировки
};