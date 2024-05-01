#include <iostream>//���������� ����� � ������
#include <windows.h>//���������� ������������� �� ������� ����������� �������
#include <conio.h>//���������� ������������� �� ������� getch
#include <vector>//���������� ����������� �������
#include "MainMenu.h"//����������� HeaderFile � Enum-����
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ ������������ �� �������
#include "FileInput.h"//����������� HeaderFile � �������� ������
#include "FileOutput.h"//����������� HeaderFile � �������� �������
#include "ConsoleInput.h"//����������� HeaderFile � ������ � �������
#include "Algoritm.h"//����������� HeaderFile � 
#include "ISort.h"//����������� HeaderFile � 
#include "RandomInput.h"//����������� HeaderFile � ��������� ������
#include "PersonalInterface.h"//����������� HeaderFile ����������������� ����������
#define QUIT 27//������ ������������ Esc �������� 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //�����������
	SetConsoleCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� �����
	SetConsoleOutputCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� ������
	int userChoice = 0; //���������� ����������������� �����
	std::vector<std::vector<int>> matrix; //������ ������� ��������
	std::vector<ISort*> InfoVec;
	ShowGreetings(); //����� �����������
	ShowTask(); //����� �������
	do
	{
		ShowInputOption(); //����� ���� ������
		userChoice = GetMenuChoise(); //���� ����������������� �������
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
		MatrixOutput(matrix);
		std::cout << std::endl;

		if (userChoice != FileInput) {
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); // ���� ����������������� �������
			if (userChoice == Yes)
			{
				InputDataFileOutput(matrix); //���������� ��������� ������� � ����
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
		ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
		userChoice = GetChoise(); // ���� ����������������� �������
		if (userChoice == Yes)
		{
			OutDataFileOutput(InfoVec,matrix); //���������� ��������� ������� � ����
		}
		matrix.clear(); //������ ������� ��������
		std::cout << "������� Esc ����� ��������� ������ ���������." << std::endl;
		std::cout << "������� Enter ����� ����������." << std::endl;
		userChoice = _getch(); //���� ���� ������� ��������� � ����������
	} while (userChoice != QUIT); //�������� ��� ��� ������� ����� ���� ������� Quit
}
