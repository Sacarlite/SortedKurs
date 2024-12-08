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
	std::ofstream  writeDataToFileStream;//�������� ������ ������ � ����
	writeDataToFileStream.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		writeDataToFileStream.open(fileName);//�������� ����� ��� ������
		writeDataToFileStream << matrix.size() << std::endl;
		writeDataToFileStream << matrix[0].size() << std::endl;
		//������ ������
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				writeDataToFileStream<< matrix[i][j] << " ";
			writeDataToFileStream << std::endl;
		}
		writeDataToFileStream.close();//�������� ������
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
	std::ofstream  writeDataToFileStream;//�������� ������ ������ � ����
	writeDataToFileStream.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		writeDataToFileStream.open(fileName);//�������� ����� ��� ������
		//������ ������
		writeDataToFileStream << "�������� �������:"<< std::endl;
		//������ ������
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				writeDataToFileStream << matrix[i][j] << " ";
			writeDataToFileStream << std::endl;
		}
		for (int k = 0; k < infoVec.size(); k++)
		{

			writeDataToFileStream << "�������� ������ ����������: " << infoVec[k]->GetName() << std::endl;
			writeDataToFileStream << "����������� ���������: " << infoVec[k]->GetComparisonCounter() << std::endl;
			writeDataToFileStream << "����������� ������������: " << infoVec[k]->GetPermutationCounter() << std::endl;
			writeDataToFileStream << "�������������� �������: " << std::endl;
			for (int i = 0; i < infoVec[k]->GetMatrix().size(); i++)
			{
				for (int j = 0; j < infoVec[k]->GetMatrix()[i].size(); ++j)
					writeDataToFileStream << std::setw(12) << infoVec[k]->GetMatrix()[i][j] << " ";
				writeDataToFileStream << std::endl;
			}
			writeDataToFileStream << std::endl;
		}
		writeDataToFileStream << "������������� �������: " << std::endl;
		int largestNumPermutations = GetLargestNumPermutations(infoVec);
		int largestNumComparison = GetLargestNumComparison(infoVec);
		writeDataToFileStream << "�����" << std::setw(INDENT - 5 + largestNumPermutations) << std::right << "������������" << std::setw(largestNumComparison + 10) << "���������" << std::endl;
		for (int i = 0; i < infoVec.size(); ++i)
		{
			std::string name = infoVec[i]->GetName();
			int indent = INDENT - static_cast<int>(name.length());
			writeDataToFileStream << name << std::setw(indent + largestNumPermutations) << infoVec[i]->GetPermutationCounter() << std::setw(largestNumComparison + 10) << infoVec[i]->GetComparisonCounter() << std::endl;
		}
		writeDataToFileStream << std::endl;
		writeDataToFileStream.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch (const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void InputDataFileOutput(std::vector<std::vector<int>> matrix)
{
	std::ifstream inputDataFromFileStream;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	inputDataFromFileStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
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
			inputDataFromFileStream.open(fileName);//������� �������� �����
			ShowOutputChoice();//������� ������ �� ������� ������ �����
			userChoice = GetChoice();//���� ����������������� ������
			if (userChoice == Yes) {

				inputDataFromFileStream.close();//�������� ������ ������ �� �����
				WriteInputData(matrix, fileName);//������� ������ � ����
			}
			else {
				inputDataFromFileStream.close();//�������� ������ ������ �� �����
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
	std::ifstream inputDataFromFileStream;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	inputDataFromFileStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
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
			inputDataFromFileStream.open(fileName);//������� �������� �����
			ShowOutputChoice();//������� ������ �� ������� ������ �����
			userChoice = GetChoice();//���� ����������������� ������
			if (userChoice == Yes) {

				inputDataFromFileStream.close();//�������� ������ ������ �� �����
				WriteOutData(infoVec, fileName,matrix);//������� ������ � ����
			}
			else {
				inputDataFromFileStream.close();//�������� ������ ������ �� �����
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

