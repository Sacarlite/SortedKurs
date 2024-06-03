#include <iostream>//Подключение библеотеки ввода и вывода
#include "PersonalInterface.h"

void ShowTask() {
	std::cout << "Необходимо составить консольную программу для сортировки массива данных" << std::endl;
	std::cout << "методами: пузырьковой, отбора, вставки, Шелла и быстрой сортировки.Вывести" << std::endl;
	std::cout << "на экран неупорядоченный(один раз) и упорядоченные(для каждого из методов)" << std::endl;
	std::cout << "массивы данных.Составить сравнительную таблицу эффективности методов, в" << std::endl;
	std::cout << "каждом методе сортировки." << std::endl;
	std::cout << "Упорядочить все четные элементы (значения элементов) столбцов по убыванию." << std::endl;
}

void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
	std::cout << "3)Случайный" << std::endl;
	std::cout << "Ввод:";
}

void ShowGreetings()
{
	std::cout << "Курсовая работа по теме сортироки. Кутькина Олеся 4304г. Вариант №12" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}


void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
	std::cout << "Ввод:";
}
