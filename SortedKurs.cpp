#include <iostream>//���������� ����� � ������
#include <windows.h>//���������� ������������� �� ������� ����������� �������
#include <conio.h>//���������� ������������� �� ������� getch
#include <vector>//���������� ����������� �������
#include "MainMenu.h"//����������� HeaderFile � Enum-����
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ����������� �� �������
#include "FileInput.h"//����������� HeaderFile � �������� ������
#include "FileOutput.h"//����������� HeaderFile � �������� �������
#include "ConsoleInput.h"//����������� HeaderFile � ������ � �������
#include "Algoritm.h"//����������� HeaderFile � ���������������� �����������
#include "ISort.h"//����������� HeaderFile � ������������
#include "RandomInput.h"//����������� HeaderFile � ��������� ������
#include "PersonalInterface.h"//����������� HeaderFile ����������������� ����������
#define QUIT 27//������ ������������ Esc �������� 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //������� �����������
	SetConsoleCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� �����
	SetConsoleOutputCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� ������
	int userChoice = 0; //���������� ����������������� �����
	std::vector<std::vector<int>> matrix; //���������������� ������� 
	std::vector<std::shared_ptr<ISort>> InfoVec;//������ �������� ���� ISort
	ShowGreetings(); //����� �����������
	ShowTask(); //����� �������
	do
	{
		ShowInputOption(); //����� ���� ������
		userChoice = GetMenuChoice(); //���� ����������������� �������
		switch (userChoice) //switch ������ ����������� ����� ��� ���������
		{
		case (ManualInput):
			matrix = ConsoleInput(); //���� ������ �� ������������ � ������� 
			break;
		case (FileInput):
			matrix = FileDataInput(); //���� ������ �� ������������ �� �����
			break;
		case (RandomInput):
			matrix = RandomDataInput(); //���� ������ �� ������������ �� �����
			break;
		}
		std::cout << "�������� �������" << std::endl;
		MatrixOutput(matrix);//����� �������� �������
		std::cout << std::endl;

		if (userChoice != FileInput) {
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoice(); // ���� ����������������� �������
			if (userChoice == Yes)
			{
				InputDataFileOutput(matrix); //���������� ������� ������� � ����
			}
		}
		std::shared_ptr<BubbleSort> bublePtr(new BubbleSort(matrix));//�������� ������ ��������� �� ����������� ����������
		bublePtr->Sort();//����� ������ ����������
		InfoVec.push_back(bublePtr);//���������� ��������� � ������
		
		std::shared_ptr<ShellSort> shellPtr (new ShellSort(matrix));//�������� ������ ��������� �� ���������� �����
		shellPtr->Sort();//����� ������ ����������
		InfoVec.push_back(shellPtr);//���������� ��������� � ������

		std::shared_ptr<InsertionSort> insertionPtr (new InsertionSort(matrix));//�������� ������ ��������� �� ���������� ��������
		insertionPtr->Sort();//����� ������ ����������
		InfoVec.push_back(insertionPtr);//���������� ��������� � ������

		std::shared_ptr<SelectionSort> selectionPtr (new SelectionSort(matrix));//�������� ������ ��������� �� ���������� �������
		selectionPtr->Sort();//����� ������ ����������
		InfoVec.push_back(selectionPtr);//���������� ��������� � ������

		std::shared_ptr<QuickSortMat> quickPtr (new QuickSortMat(matrix));//�������� ������ ��������� �� ������� ����������
		quickPtr->Sort();//����� ������ ����������
		InfoVec.push_back(quickPtr);//���������� ��������� � ������

		SortInfoOutput(InfoVec);//����� ����������� ���������� �� �������
		ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
		userChoice = GetChoice(); // ���� ����������������� �������
		if (userChoice == Yes)
		{
			OutDataFileOutput(InfoVec,matrix); //���������� ��������� ������� � ����
		}
		matrix.clear(); //������ �������
		InfoVec.clear();//������ ��������������� �������
		std::cout << "������� Esc ����� ��������� ������ ���������." << std::endl;
		std::cout << "������� Enter ����� ����������." << std::endl;
		userChoice = _getch(); //���� ���� ������� ��������� � ����������
	} while (userChoice != QUIT); //�������� ��� ��� ������� ����� ���� ������� Quit
}
