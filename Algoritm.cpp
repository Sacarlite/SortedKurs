#include "Algoritm.h"
/*���������� ������ �������� �� �������*/
std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec,int j) {
	std::vector<int> evenVec;
	for (int i = 0; i < originalVec.size(); i++) {//������� �������� ������� � ����������� j
		if (originalVec[i][j] % 2 == 0) {//�������� ��������
			evenVec.push_back(originalVec[i][j]);//���������� � ����� �������
		}
	}
	return evenVec;
}
/*������� ��������������� �������� � ������� � �������� j*/
//�������� ������������ � ������� ���������� �� �������� �����
void ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>>& originalVec, int j) {

	int counter = 0;//���������� ��������
	for (int i = 0; i < originalVec.size(); i++) {//������� �������� ������� � ����������� j
		if (originalVec[i][j] % 2 == 0) {//�������� ��������
			originalVec[i][j] = tmp_vec[counter];//������� ���������������� �������� 
			counter++;//����������� ��������
		}
	}
}
/*������� ������ ������ �������� ����� ������������*/
int GetLargestNumPermutations(std::vector<std::shared_ptr<ISort>> infoVec)
{
	int max = infoVec[0]->GetPermutationCounter();//������������ �������� ��������� ������� ��������
	for (int i = 1; i < infoVec.size(); ++i)//������� �������� ������� � �����������
	{
		if (infoVec[i]->GetPermutationCounter() > max) {//����������� �������� � ����������
			max = infoVec[i]->GetPermutationCounter();//������������ �������� ���������
		}
	}
	return static_cast<int>(std::to_string(max).length());//�������������� ����� � ������
}
/*������� ������ ������ �������� ����� ���������*/
int GetLargestNumComparison(std::vector<std::shared_ptr<ISort>> infoVec)
{
	int num = infoVec[0]->GetComparisonCounter();//������������ �������� ��������� ������� ��������
	for (int i = 1; i < infoVec.size(); ++i) // ������� �������� ������� � �����������
	{
		if (infoVec[i]->GetComparisonCounter() > num) {//����������� �������� � ����������
			num = infoVec[i]->GetComparisonCounter();//������������ �������� ���������
		}
	}
	return static_cast<int>(std::to_string(num).length());//�������������� ����� � ������
}
