#pragma once
#include <math.h>
#include <iostream>
#include <vector>

class ISort
{
protected:
	int comparison_counter = 0;
	int permutation_counter = 0;
	std::vector<std::vector<int>> matrix;
	std::string name;
public:
	std::string GetName();
	int GetComparisonCounter();
	int GetPermutationCounter();
	std::vector<std::vector<int>> GetMatrix();
	ISort(std::vector<std::vector<int>> matrix);
	virtual void Sort()=0;
	~ISort() {
		if (!matrix.empty()) {
			matrix.clear();
		}
	};
};
class BubbleSort :public ISort {

public:
	BubbleSort(std::vector<std::vector<int>> matrix);
	void Sort() override;
};
class SelectionSort :public ISort {
public:
	SelectionSort(std::vector<std::vector<int>> matrix);
	void Sort() override;

};
class InsertionSort :public ISort {
public:
	InsertionSort(std::vector<std::vector<int>> matrix);
	void Sort() override;
};
class ShellSort :public ISort {
public:
	ShellSort(std::vector<std::vector<int>> matrix);
	void Sort() override;
};
class QuickSortMat :public ISort {
private:
	int tmp_comparison_counter=0;
	int tmp_permutation_counter=0;
	void QuickSort(std::vector<int>& arr, int start, int end);
	int Partition(std::vector<int>& arr, int start, int end);
public:
	QuickSortMat(std::vector<std::vector<int>> matrix);
	void Sort() override;
	
};