#include "ConsoleInput.h"

std::vector<std::vector<int>> ConsoleInput()
{
	std::vector<std::vector<int>> matrix;
	std::cout << "������� ����������� ������� n(���-�� �����)Xm(���-�� ��������). ����������� ������ ������� 2x2. ���������� ��� ��� ������ ��������� ���-�� ����� ������ ���� �� ������ 2�." << std::endl;
	std::cout << "������� n=";
	int n = GetPositiveIntMoreThen1();
	std::cout << "������� m=";
	int m = GetPositiveIntMoreThen0();
	for (int i = 0; i < n; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < m; j++) {

			std::cout << "matrix[" << i + 1 << "][" << j + 1 << "] = " << std::endl;
			row.push_back(GetPositiveInt());
			std::cout << "" << std::endl;
		}
		matrix.push_back(row);
	}
	return matrix;
}
