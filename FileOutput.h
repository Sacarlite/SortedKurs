#pragma once
#include <vector>//����������� ���������� �������
#include "ISort.h"//����������� HeaderFile � ������������
#include "Algoritm.h"//����������� HeaderFile � �����������
void InputDataFileOutput(std::vector<std::vector<int>> matrix);//����� �������� ������ � ����
void OutDataFileOutput(std::vector<std::shared_ptr<ISort>> InfoVec, std::vector<std::vector<int>> matrix);//����� ���������� � ����������� � ����