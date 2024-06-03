#pragma once
#include <vector>//����������� ���������� �������
#include <iostream>//���������� ����� � ������
#include <string>//���������� �����
#include "ISort.h"//����������� HeaderFile � ������������
/*������� �������������� ��� ���������� � �������� ������ �������� ������*/
std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec, int j);//���������� ������ �������� �� �������
void ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>>& originalVec, int j);//������� ��������������� �������� � ������� � �������� j
/*������� �������������� ��� ���������������� ������*/
int GetLargestNumPermutations(std::vector<std::shared_ptr<ISort>> infoVec);//������� ������ ������ �������� ����� ������������
int GetLargestNumComparison(std::vector<std::shared_ptr<ISort>> infoVec);//������� ������ ������ �������� ����� ���������