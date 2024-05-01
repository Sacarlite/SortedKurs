#pragma once
#include "ISort.h"
#include <iomanip>
#include <ctime>
#include <string>

std::vector<int> EvenSampling(std::vector<std::vector<int>> originalVec, int j);
std::vector<std::vector<int>> ReturningValues(std::vector<int> tmp_vec, std::vector<std::vector<int>> originalVec, int j);
int GetLargestNumPermutations(std::vector<ISort*> infoVec);
int GetLargestNumComparison(std::vector<ISort*> infoVec);

