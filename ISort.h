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
public:
	ISort(std::vector<std::vector<int>> matrix);
	virtual void Sort()=0;
	~ISort() {
		if (!matrix.empty()) {
			matrix.clear();
		}
	};
};
class BubbleSort :public ISort {
private:
	std::string name = "BubbleSort";
public:
	BubbleSort(std::vector<std::vector<int>> matrix);
	std::string GetName();
	void Sort() override;
};
class SelectionSort :public ISort {
private:
	std::string name = "SelectionSort";
public:
	std::string GetName();
	SelectionSort(std::vector<std::vector<int>> matrix);
	void Sort() override;

};
class InsertionSort :public ISort {
private:
	std::string name = "InsertionSort";
public:
	std::string GetName();
	InsertionSort(std::vector<std::vector<int>> matrix);
	void Sort() override;
};
class ShellSort :public ISort {
private:
	std::string name = "ShellSort";
public:
	std::string GetName();
	ShellSort(std::vector<std::vector<int>> matrix);
	void Sort() override;
};
class QuickSortMat :public ISort {
private:
	std::string name = "QuickSort";
	int tmp_comparison_counter=0;
	int tmp_permutation_counter=0;
	void QuickSort(std::vector<int>& arr, int start, int end);
	int Partition(std::vector<int>& arr, int start, int end);
public:
	std::string GetName();
	QuickSortMat(std::vector<std::vector<int>> matrix);
	void Sort() override;
	
};