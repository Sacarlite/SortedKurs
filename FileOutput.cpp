#include "FileOutput.h"
#include <fstream>
#include <iostream>
#include "Checks.h"
#include "MainMenu.h"
#include "PersonalInterface.h"
#include <filesystem>
class FileWriteException//Пользовательский класс ошибок фаилового взаимодействия
{
public:
	FileWriteException(std::string message) : message{ message } {}//Конструктор класса 
	std::string getMessage() const { return message; }//Возврат сообщение об ошибки
private:
	std::string message;//Поле хранящее сообщение об ошибке
};
void WriteInputData(std::vector<std::vector<int>> matrix, std::string fileName)//Функция записи данных квартир в фаил
{
	std::ofstream  writeDataToFileStream;//Создания потока записи в фаил
	writeDataToFileStream.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		writeDataToFileStream.open(fileName);//открытие фаила для записи
		writeDataToFileStream << matrix.size() << std::endl;
		writeDataToFileStream << matrix[0].size() << std::endl;
		//Запись данных
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				writeDataToFileStream<< matrix[i][j] << " ";
			writeDataToFileStream << std::endl;
		}
		writeDataToFileStream.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch (const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void WriteOutData(std::vector<std::shared_ptr<ISort>> infoVec, std::string fileName, std::vector<std::vector<int>> matrix)//Функция записи данных квартир в фаил
{
	const int INDENT = 26;
	std::ofstream  writeDataToFileStream;//Создания потока записи в фаил
	writeDataToFileStream.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		writeDataToFileStream.open(fileName);//открытие фаила для записи
		//Запись данных
		writeDataToFileStream << "Исходная матрица:"<< std::endl;
		//Запись данных
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				writeDataToFileStream << matrix[i][j] << " ";
			writeDataToFileStream << std::endl;
		}
		for (int k = 0; k < infoVec.size(); k++)
		{

			writeDataToFileStream << "Название метода сортировки: " << infoVec[k]->GetName() << std::endl;
			writeDataToFileStream << "Колличество сравнений: " << infoVec[k]->GetComparisonCounter() << std::endl;
			writeDataToFileStream << "Колличество перестановок: " << infoVec[k]->GetPermutationCounter() << std::endl;
			writeDataToFileStream << "Результирующая матрица: " << std::endl;
			for (int i = 0; i < infoVec[k]->GetMatrix().size(); i++)
			{
				for (int j = 0; j < infoVec[k]->GetMatrix()[i].size(); ++j)
					writeDataToFileStream << std::setw(12) << infoVec[k]->GetMatrix()[i][j] << " ";
				writeDataToFileStream << std::endl;
			}
			writeDataToFileStream << std::endl;
		}
		writeDataToFileStream << "Сравнительная таблица: " << std::endl;
		int largestNumPermutations = GetLargestNumPermutations(infoVec);
		int largestNumComparison = GetLargestNumComparison(infoVec);
		writeDataToFileStream << "Метод" << std::setw(INDENT - 5 + largestNumPermutations) << std::right << "Перестановки" << std::setw(largestNumComparison + 10) << "Сравнения" << std::endl;
		for (int i = 0; i < infoVec.size(); ++i)
		{
			std::string name = infoVec[i]->GetName();
			int indent = INDENT - static_cast<int>(name.length());
			writeDataToFileStream << name << std::setw(indent + largestNumPermutations) << infoVec[i]->GetPermutationCounter() << std::setw(largestNumComparison + 10) << infoVec[i]->GetComparisonCounter() << std::endl;
		}
		writeDataToFileStream << std::endl;
		writeDataToFileStream.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch (const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void InputDataFileOutput(std::vector<std::vector<int>> matrix)
{
	std::ifstream inputDataFromFileStream;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	inputDataFromFileStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			inputDataFromFileStream.open(fileName);//Попытка открытия фаила
			ShowOutputChoice();//Функция вывода на консоль выбора файла
			userChoice = GetChoice();//Ввод пользовательского выбора
			if (userChoice == Yes) {

				inputDataFromFileStream.close();//Закрытия потока чтения из фаила
				WriteInputData(matrix, fileName);//Функция записи в фаил
			}
			else {
				inputDataFromFileStream.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteInputData(matrix, fileName);//Функция записи в фаил
				break;
			}
			catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}


}

void OutDataFileOutput(std::vector<std::shared_ptr<ISort>> infoVec, std::vector<std::vector<int>> matrix)
{
	std::ifstream inputDataFromFileStream;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	inputDataFromFileStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			inputDataFromFileStream.open(fileName);//Попытка открытия фаила
			ShowOutputChoice();//Функция вывода на консоль выбора файла
			userChoice = GetChoice();//Ввод пользовательского выбора
			if (userChoice == Yes) {

				inputDataFromFileStream.close();//Закрытия потока чтения из фаила
				WriteOutData(infoVec, fileName,matrix);//Функция записи в фаил
			}
			else {
				inputDataFromFileStream.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteOutData(infoVec, fileName,matrix);//Функция записи в фаил
				break;
			}
			catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}


}

