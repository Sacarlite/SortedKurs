#include "FileOutput.h"
#include <fstream>
#include <iostream>
#include "Checks.h"
#include "MainMenu.h"
#include "PersonalInterface.h"
#include <filesystem>
class FileWriteException//���������������� ����� ������ ��������� ��������������
{
public:
	FileWriteException(std::string message) : message{ message } {}//����������� ������ 
	std::string getMessage() const { return message; }//������� ��������� �� ������
private:
	std::string message;//���� �������� ��������� �� ������
};
void WriteInputData(std::vector<std::vector<int>> matrix, std::string fileName)//������� ������ ������ ������� � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		out << matrix.size() << std::endl;
		out << matrix[0].size() << std::endl;
		//������ ������
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				out<< matrix[i][j] << " ";
			out << std::endl;
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch (const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void WriteOutData(std::vector<std::shared_ptr<ISort>> infoVec, std::string fileName, std::vector<std::vector<int>> matrix)//������� ������ ������ ������� � ����
{
	const int INDENT = 26;
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		//������ ������
		out << "�������� �������:"<< std::endl;
		//������ ������
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				out << matrix[i][j] << " ";
			out << std::endl;
		}
		for (int k = 0; k < infoVec.size(); k++)
		{

			out << "�������� ������ ����������: " << infoVec[k]->GetName() << std::endl;
			out << "����������� ���������: " << infoVec[k]->GetComparisonCounter() << std::endl;
			out << "����������� ������������: " << infoVec[k]->GetPermutationCounter() << std::endl;
			out << "�������������� �������: " << std::endl;
			for (int i = 0; i < infoVec[k]->GetMatrix().size(); i++)
			{
				for (int j = 0; j < infoVec[k]->GetMatrix()[i].size(); ++j)
					out << std::setw(12) << infoVec[k]->GetMatrix()[i][j] << " ";
				out << std::endl;
			}
			out << std::endl;
		}
		out << "������������� �������: " << std::endl;
		int largestNumPermutations = GetLargestNumPermutations(infoVec);
		int largestNumComparison = GetLargestNumComparison(infoVec);
		out << "�����" << std::setw(INDENT - 5 + largestNumPermutations) << std::right << "������������" << std::setw(largestNumComparison + 10) << "���������" << std::endl;
		for (int i = 0; i < infoVec.size(); ++i)
		{
			std::string name = infoVec[i]->GetName();
			int indent = INDENT - static_cast<int>(name.length());
			out << name << std::setw(indent + largestNumPermutations) << infoVec[i]->GetPermutationCounter() << std::setw(largestNumComparison + 10) << infoVec[i]->GetComparisonCounter() << std::endl;
		}
		out << std::endl;
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch (const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void InputDataFileOutput(std::vector<std::vector<int>> matrix)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {

				out2.close();//�������� ������ ������ �� �����
				WriteInputData(matrix, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteInputData(matrix, fileName);//������� ������ � ����
				break;
			}
			catch (FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}


}

void OutDataFileOutput(std::vector<std::shared_ptr<ISort>> infoVec, std::vector<std::vector<int>> matrix)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {

				out2.close();//�������� ������ ������ �� �����
				WriteOutData(infoVec, fileName,matrix);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteOutData(infoVec, fileName,matrix);//������� ������ � ����
				break;
			}
			catch (FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}


}

