#pragma once
#include <vector>//����������� ���������� �������
#include <iostream>//���������� ����� � ������
#include <string>//���������� �����
#include <iomanip>//���������� ���������������� ������
#include "ISort.h"//����������� HeaderFile � ������������
#include "Algoritm.h"//����������� HeaderFile � �����������

void MatrixOutput(std::vector<std::vector<int>> intVec);//����� ������� �� �������
void SortInfoOutput(std::vector<std::shared_ptr<ISort>> infoVec);//����� ���������� � ����������� �� �������