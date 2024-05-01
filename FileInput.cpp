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
			if (!std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
				std::cout << "Фаил открыт успешно. " << std::endl;
			}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		try {
			file.open(fileName);//Открытия фаила для чтения
			std::vector<int> tmpVec;
			std::string str;
			int n = CheckLineI(file);
			int m = CheckLineI(file);
			for (int i = 0; i < n; i++) {
				str = CheckLineS(file);
				std::vector<std::string> strin;
				std::string tmp_string;
				for (int j = 0; j <= str.size(); j++) {
					if ((!isdigit(str[j])) || str[j] == '\n')
					{
						strin.push_back(tmp_string);
						tmp_string = "";
					}
					tmp_string += str[j];
				}

				for (int k = 0; k < strin.size(); k++) {
					if (strin[k] == " ") {
						strin.erase(strin.begin() + k);
					}
				}
				if (strin.size() != m) {
					throw std::exception();
				}
				for (int j = 0; j < m; j++) {
					if (std::stoi(strin[j]) < 0) {
						throw std::exception();
					}
					tmpVec.push_back(std::stoi(strin[j]));
				}
				matrix.push_back(tmpVec);
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
