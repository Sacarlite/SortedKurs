#include <iostream>//Библеотека ввода и вывода
#include <windows.h>//Библеотека ответственная за русскую локализацию консоли
#include <conio.h>//Библеотека ответственная за функцию getch
#include <vector>//Библеотека подключения вектора
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом списка апартаментов на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "ConsoleInput.h"//Подключение HeaderFile с вводом с консоли
#include "Algoritm.h"//Подключение HeaderFile с 
#include "ISort.h"//Подключение HeaderFile с 
#include "RandomInput.h"//Подключение HeaderFile с рандомным вводом
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#define QUIT 27//Макрос присваивания Esc значение 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //Локализация
	SetConsoleCP(1251); //функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251); //функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0; //Переменная пользовательского ввода
	std::vector<std::vector<int>> matrix; //Вектор вводных животных
	std::vector<ISort*> InfoVec;
	ShowGreetings(); //Вывод приветствия
	ShowTask(); //Вывод задания
	do
	{
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetMenuChoise(); //Ввод пользовательского решения
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
		MatrixOutput(matrix);
		std::cout << std::endl;

		if (userChoice != FileInput) {
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); // Ввод пользовательского решения
			if (userChoice == Yes)
			{
				InputDataFileOutput(matrix); //Сохранение итогового массива в фаил
			}
		}
		BubbleSort bubbleSort(matrix);
		bubbleSort.Sort();
		InfoVec.push_back(&bubbleSort);
		
		ShellSort shellSort(matrix);
		shellSort.Sort();
		InfoVec.push_back(&shellSort);

		InsertionSort insertionSort(matrix);
		insertionSort.Sort();
		InfoVec.push_back(&insertionSort);

		SelectionSort selectionSort(matrix);
		selectionSort.Sort();
		InfoVec.push_back(&selectionSort);

		QuickSortMat quickSort(matrix);
		quickSort.Sort();
		InfoVec.push_back(&quickSort);
		SortInfoOutput(InfoVec);
		ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
		userChoice = GetChoise(); // Ввод пользовательского решения
		if (userChoice == Yes)
		{
			OutDataFileOutput(InfoVec,matrix); //Сохранение итогового массива в фаил
		}
		matrix.clear(); //Чистка вектора животных
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch(); //Ввод кода символа введённого с клавиатуры
	} while (userChoice != QUIT); //Проверка что код символа равен коду макроса Quit
}
