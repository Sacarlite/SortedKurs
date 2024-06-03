#include "FileInput.h"

std::vector<std::vector<int>> FileDataInput()
{
	std::vector<std::vector<int>> matrix;//Объявления матрицы
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к фаилу
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			file.open(fileName);//Открытия фаила для чтения
			if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
				std::cout << "Фаил открыт успешно. " << std::endl;
			}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		try {
			
			std::vector<int> tmpVec;//Объявление строки матрицы 
			std::string str;//Объявление вводимой строки 
			int n = CheckLineIMoreThen1(file);//Считывания количества строк
			int m = CheckLineIMoreThen0(file);//Считывая количества столбоцов 
			for (int i = 0; i < n; i++) {
				str = CheckLineS(file);//Считывния строки
				std::vector<std::string> strin;
				std::string tmp_string;
				/*Считывания эдемента матрицы*/
				for (int j = 0; j <= str.size(); j++) {
					if ((!isdigit(str[j])) || str[j] == '\n')
					{
						strin.push_back(tmp_string);
						tmp_string = "";
					}
					tmp_string += str[j];
				}
				//Удаляем пробелы
				for (int k = 0; k < strin.size(); k++) {
					if (strin[k]!=" "&& strin[k] != "") {
						tmpVec.push_back(std::stoi(strin[k]));
					}
				}
				if (tmpVec.size() != m) {//Если столбцов больше чем должно быть генирируется ошибка
					tmpVec.clear();
					throw std::exception();
				}
				matrix.push_back(tmpVec);//Добавление строки матрицы
				tmpVec.clear();
			}
		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << "Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			file.close();
			continue;
		}
		catch (const CheckException err) {//Обработка ошибки пользовательского ввода  
			std::cout << err.GetMessage() << std::endl;//Вывод сообщения об ошибки
			file.close();//Закрытия потока
			continue;
		}
		file.close();//закрытие потока
		return  matrix;
	}
}
