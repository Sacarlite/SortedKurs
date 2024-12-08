#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include <iostream>//���������� ����� � ������
#include <fstream>//���������� ��������� ����� � ������
#include <string>//���������� �����
/*������� ����� � ������� ������ �������������� �������� ������ 0*/
int GetPositiveIntMoreThen0()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//������� ������ � ������������� ��������
            if (value > 0) {
                std::cin.clear();//������� ����� ����� � ������� ��������� 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
                return value;

            }
            else {
                throw std::exception();//������������ ������
            }
        }
        catch (std::exception&) {//��������� ������������ ������
            std::cin.clear();//������� ����� ����� � ������� ��������� 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
            std::cout << "���� ������� �� ���������� ������. ��������� ����." << std::endl;//����� ��������� �� ������
        }

    }
}
/*������� ����� � ������� ������  ��������*/
int GetInt()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//������� ������ � ������������� ��������
                std::cin.clear();//������� ����� ����� � ������� ��������� 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
                return value;
        }
        catch (std::exception&) {//��������� ������������ ������
            std::cin.clear();//������� ����� ����� � ������� ��������� 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
            std::cout << "���� ������� �� ���������� ������. ��������� ����." << std::endl;//����� ��������� �� ������
        }

    }
}
/*������� ����� ����������������� ������*/
int GetChoice()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//�������������� ������ � ������������� ��� ������
            if ((value == 1 || value == 2) && str.length() == 1) {
                std::cin.clear();//������� ����� ����� � ������� ��������� 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
                return value;

            }
            else {
                throw std::exception();//������ ������
            }
        }
        catch (std::exception&) {//��������� ������
            std::cin.clear();//������� ����� ����� � ������� ��������� 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
            std::cout << "���� ������� �� ���������� ������. ��������� ����." << std::endl;
        }
    }
}
/*������� ����� ����������������� ������ ������ ����*/
int GetMenuChoice()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//�������������� ������ � ������������� ��� ������
            if ((value == 1 || value == 2||value==3)&&str.length()==1) {
                std::cin.clear();//������� ����� ����� � ������� ��������� 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
                return value;

            }
            else {
                throw std::exception();//������ ������
            }
        }
        catch (std::exception&) {//��������� ������
            std::cin.clear();//������� ����� ����� � ������� ��������� 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������������� ���� �������� � ������
            std::cout << "���� ������� �� ���������� ������. ��������� ����." << std::endl;
        }
    }
}
int CheckLineIMoreThen0(std::ifstream& file)
{
    std::string temp_v = "";//���������� ���������� ������
    try
    {
        std::getline(file, temp_v);//������ ������ ������� �� ������� � ���������� temp_s
        int temp_i = stoi(temp_v);//�������������� ������ � ������������� ���
        if (temp_i < 1)

        {
            throw  std::exception();//������ ������
        }
        else

            return temp_i;
    }
    catch (const std::exception&)//��������� ������
    {
        throw CheckException("��������� ������ ��� ������ ���������� �� �����");//������ ������ ����������������� ����
    }
}
/*������� ����� ������ �������� �� �����*/
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        return temp_v;

    }
    catch (const std::exception&)
    {
        throw CheckException("��������� ������ ��� ������ ���������� �� �����");//������ ������ ����������������� ����
    }
}
