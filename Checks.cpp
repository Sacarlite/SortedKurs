#include "Checks.h"
#include <iostream>
#include <fstream>
#include <string>
int GetPositiveIntMoreThen1()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//������� ������ � ������������� ��������
            if (value > 1) {
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

int GetPositiveInt()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//������� ������ � ������������� ��������
            if (value >= 0) {
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

int GetChoise()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//�������������� ������ � ������������� ��� ������
            if (value == 1 || value == 2) {
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

int GetMenuChoise()
{
    while (true) {
        std::string str;//���������� ���������� ������
        std::cin >> str;//���� ������ � �������
        try {
            int value = std::stoi(str);//�������������� ������ � ������������� ��� ������
            if (value == 1 || value == 2||value==3) {
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

int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";//���������� ���������� ������
    try
    {
        std::getline(file, temp_v);//������ ������ ������� �� ������� � ���������� temp_s
        int temp_i = stoi(temp_v);//�������������� ������ � ������������� ���
        if (temp_i <= 1)

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
