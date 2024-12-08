#include <iostream>//Библеотека ввода и вывода
#include <windows.h>//Библеотека ответственная за русскую локализацию консоли
#include <conio.h>//Библеотека ответственная за функцию getch
#include <vector>//Библеотека подключения вектора
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом результатов на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "ConsoleInput.h"//Подключение HeaderFile с вводом с консоли
#include "Algoritm.h"//Подключение HeaderFile с вспомогательными алгоритмами
#include "ISort.h"//Подключение HeaderFile с сортировками
#include "RandomInput.h"//Подключение HeaderFile с рандомным вводом
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#define QUIT 27//Макрос присваивания Esc значение 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //Русская локализация
	SetConsoleCP(1251); //функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251); //функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0; //Переменная пользовательского ввода
	std::vector<std::vector<int>> matrix; //Пользовательская матрица 
	std::vector<std::shared_ptr<ISort>> InfoVec;//Вектор объектов типа ISort
	ShowGreetings(); //Вывод приветствия
	ShowTask(); //Вывод задания
	do
	{
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetMenuChoice(); //Ввод пользовательского решения
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (ManualInput):
			matrix = ConsoleInput(); //Ввод данных об апартаментов с консоли 
			break;
		case (FileInput):
			matrix = FileDataInput(); //Ввод данных об апартаментов из файла
			break;
		case (RandomInput):
			matrix = RandomDataInput(); //Ввод данных об апартаментов из файла
			break;
		}
		std::cout << "Исходная матрица" << std::endl;
		MatrixOutput(matrix);//Вывод исходной матрицы
		std::cout << std::endl;

		if (userChoice != FileInput) {
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoice(); // Ввод пользовательского решения
			if (userChoice == Yes)
			{
				InputDataFileOutput(matrix); //Сохранение введёной матрицы в файл
			}
		}
		std::shared_ptr<BubbleSort> bublePtr(new BubbleSort(matrix));//Создание умного указателя на пузырьковую сортировку
		bublePtr->Sort();//Вызов метода сортировки
		InfoVec.push_back(bublePtr);//Добавление указателя в вектор
		
		std::shared_ptr<ShellSort> shellPtr (new ShellSort(matrix));//Создание умного указателя на сортировку Шелла
		shellPtr->Sort();//Вызов метода сортировки
		InfoVec.push_back(shellPtr);//Добавление указателя в вектор

		std::shared_ptr<InsertionSort> insertionPtr (new InsertionSort(matrix));//Создание умного указателя на сортировку вставкой
		insertionPtr->Sort();//Вызов метода сортировки
		InfoVec.push_back(insertionPtr);//Добавление указателя в вектор

		std::shared_ptr<SelectionSort> selectionPtr (new SelectionSort(matrix));//Создание умного указателя на сортировку выбором
		selectionPtr->Sort();//Вызов метода сортировки
		InfoVec.push_back(selectionPtr);//Добавление указателя в вектор

		std::shared_ptr<QuickSortMat> quickPtr (new QuickSortMat(matrix));//Создание умного указателя на быструю сортировку
		quickPtr->Sort();//Вызов метода сортировки
		InfoVec.push_back(quickPtr);//Добавление указателя в вектор

		SortInfoOutput(InfoVec);//Вывод результатов сортировок на консоль
		ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
		userChoice = GetChoice(); // Ввод пользовательского решения
		if (userChoice == Yes)
		{
			OutDataFileOutput(InfoVec,matrix); //Сохранение итогового массива в фаил
		}
		matrix.clear(); //Чистка матрицы
		InfoVec.clear();//Чистка информационного вектора
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch(); //Ввод кода символа введённого с клавиатуры
	} while (userChoice != QUIT); //Проверка что код символа равен коду макроса Quit
}
