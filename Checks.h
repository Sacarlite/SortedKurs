#pragma once
#include <iostream>//���������� ����� � ������
#include "CheckException.h"//����������� HeaderFile � ������� ������ ����������������� �����
int GetPositiveIntMoreThen1();//������� ����� � ������� ������ �������������� �������� ������ 1
int GetPositiveIntMoreThen0();//������� ����� � ������� ������ �������������� �������� ������ 0
int GetInt();//������� ����� � ������� ������  ��������
int GetChoise();//������� ����� ����������������� ������
int GetMenuChoise();//������� ����� ����������������� ������ ������ ����
int CheckLineIMoreThen1(std::ifstream& file);//������� ����� �������������� �������� �� ����� ������ 1
int CheckLineIMoreThen0(std::ifstream& file);//������� ����� �������������� �������� �� ����� ������ 0
std::string CheckLineS(std::ifstream& file);//������� ����� ������  �� �����