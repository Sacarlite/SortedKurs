#pragma once
#include <iostream>//���������� ����� � ������
#include "CheckException.h"//����������� HeaderFile � ������� ������ ����������������� �����
int GetPositiveIntMoreThen0();//������� ����� � ������� ������ �������������� �������� ������ 0
int GetInt();//������� ����� � ������� ������  ��������
int GetChoice();//������� ����� ����������������� ������
int GetMenuChoice();//������� ����� ����������������� ������ ������ ����
int CheckLineIMoreThen0(std::ifstream& file);//������� ����� �������������� �������� �� ����� ������ 0
std::string CheckLineS(std::ifstream& file);//������� ����� ������  �� �����