#include "Algoritm.h"

std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec,int j) {
	std::vector<int> evenVec;
	for (int i = 0; i < originalVec.size(); i++) {
		if (originalVec[i][j] % 2 == 0) {
			evenVec.push_back(originalVec[i][j]);
		}
	}
	return evenVec;
}
//ÀÕÒÓÍÃ ÊÎÑÒÛËÜ
std::vector<std::vector<int>> ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>> originalVec, int j) {
	std::vector<std::vector<int>> tmp_originalVec;
	tmp_originalVec.assign(originalVec.begin(), originalVec.end());
	int counter = 0;
	for (int i = 0; i < tmp_originalVec.size(); i++) {
		if (tmp_originalVec[i][j] % 2 == 0) {
			tmp_originalVec[i][j] = tmp_vec[counter];
			counter++;
		}
	}
	return tmp_originalVec;
}

int GetLargestNumPermutations(std::vector<ISort*> infoVec)
{
	int num = infoVec[0]->GetPermutationCounter();
	for (int i = 1; i < infoVec.size(); ++i)
	{
		if (infoVec[i]->GetPermutationCounter() > num) {
			num = infoVec[i]->GetPermutationCounter();
		}
	}
	return static_cast<int>(std::to_string(num).length());
}

int GetLargestNumComparison(std::vector<ISort*> infoVec)
{
	int num = infoVec[0]->GetComparisonCounter();
	for (int i = 1; i < infoVec.size(); ++i)
	{
		if (infoVec[i]->GetComparisonCounter() > num) {
			num = infoVec[i]->GetComparisonCounter();
		}
	}
	return static_cast<int>(std::to_string(num).length());
}