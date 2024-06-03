#include "FileInput.h"

std::vector<std::vector<int>> FileDataInput()
{
	std::vector<std::vector<int>> matrix;//���������� �������
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			file.open(fileName);//�������� ����� ��� ������
			if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
				std::cout << "���� ������ �������. " << std::endl;
			}
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
			continue;

		}
		try {
			
			std::vector<int> tmpVec;//���������� ������ ������� 
			std::string str;//���������� �������� ������ 
			int n = CheckLineIMoreThen1(file);//���������� ���������� �����
			int m = CheckLineIMoreThen0(file);//�������� ���������� ��������� 
			for (int i = 0; i < n; i++) {
				str = CheckLineS(file);//��������� ������
				std::vector<std::string> strin;
				std::string tmp_string;
				/*���������� �������� �������*/
				for (int j = 0; j <= str.size(); j++) {
					if ((!isdigit(str[j])) || str[j] == '\n')
					{
						strin.push_back(tmp_string);
						tmp_string = "";
					}
					tmp_string += str[j];
				}
				//������� �������
				for (int k = 0; k < strin.size(); k++) {
					if (strin[k]!=" "&& strin[k] != "") {
						tmpVec.push_back(std::stoi(strin[k]));
					}
				}
				if (tmpVec.size() != m) {//���� �������� ������ ��� ������ ���� ������������ ������
					tmpVec.clear();
					throw std::exception();
				}
				matrix.push_back(tmpVec);//���������� ������ �������
				tmpVec.clear();
			}
		}
		catch (const std::exception) {//��������� ������
			std::cout << "��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			file.close();
			continue;
		}
		catch (const CheckException err) {//��������� ������ ����������������� �����  
			std::cout << err.GetMessage() << std::endl;//����� ��������� �� ������
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		return  matrix;
	}
}
