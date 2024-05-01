#include "ISort.h"
#include"Algoritm.h"

ISort::ISort(std::vector<std::vector<int>>_matrix) :matrix{ _matrix } {}
std::string ISort::GetName() {
    return name;
}
int ISort::GetComparisonCounter()
{
    return comparison_counter;
}
int ISort::GetPermutationCounter()
{
    return permutation_counter;
}
std::vector<std::vector<int>> ISort::GetMatrix()
{
    return matrix;
}
void SelectionSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
    int min = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix,i);
        if (tmp_vec.size() >= 2) {
            for (int j = 0; j < tmp_vec.size(); j++)
            {
                min = j; // запоминаем индекс текущего элемента
                // ищем минимальный элемент чтобы поместить на место i-ого
                for (int k = j + 1; k < tmp_vec.size(); k++)  // для остальных элементов после i-ого
                {
                    tmp_comparison_counter++;
                    if (tmp_vec[k] < tmp_vec[min]) // если элемент меньше минимального,
                        min = k;       // запоминаем его индекс в max
                }
                if (min != j) {
                    std::swap(tmp_vec[j], tmp_vec[min]);
                    tmp_permutation_counter++;
                }

            }
            std::reverse(tmp_vec.begin(), tmp_vec.end());
            matrix=  ReturningValues(tmp_vec, matrix,i);
        }
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
SelectionSort::SelectionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "SelectionSort";
}

void InsertionSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix, i);
        if (tmp_vec.size() >= 2) {
            for (int k = 1; k < tmp_vec.size(); k++)
            {

                int temp = tmp_vec[k];
                int j = k - 1;
                tmp_comparison_counter++;
                while (j >= 0 && temp < tmp_vec[j])
                {
                    tmp_comparison_counter++;
                    tmp_permutation_counter++;
                    tmp_vec[j + 1] = tmp_vec[j];
                    j--;
                    if (j == 0)
                        tmp_comparison_counter--;

                }
                tmp_vec[j + 1] = temp;
            }
            std::reverse(tmp_vec.begin(), tmp_vec.end());
            matrix= ReturningValues(tmp_vec, matrix, i);
        }
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
InsertionSort::InsertionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "InsertionSort";
}

void ShellSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
 
    for (int j = 0; j < matrix[0].size(); j++)
    {
        std::vector<int> tmp_vec = EvenSampling(matrix,j);
        if (tmp_vec.size() >= 2) {
            for (int gap = static_cast<unsigned int>(tmp_vec.size()) / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < tmp_vec.size(); i++) {

                    int temp = tmp_vec[i];
                    int k;
                    tmp_comparison_counter++;
                    for (k = i; k >= gap && tmp_vec[k - gap] > temp; k -= gap) {
                        tmp_vec[k] = tmp_vec[k - gap]; tmp_permutation_counter++;
                    }
                    tmp_vec[k] = temp;
                }
            }
        }
        std::reverse(tmp_vec.begin(), tmp_vec.end());
        matrix= ReturningValues(tmp_vec, matrix, j);
}
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
ShellSort::ShellSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "ShellSort";
}

void BubbleSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
   
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix,i);
        if (tmp_vec.size() >= 2) {
            for (int j = 0; j < tmp_vec.size(); j++) {
                bool flag = true;
                for (int k = 0; k < tmp_vec.size() - (j + 1); k++) {
                    tmp_comparison_counter++;
                    if (tmp_vec[k] > tmp_vec[k + 1]) {
                        flag = false;
                        std::swap(tmp_vec[k], tmp_vec[k + 1]);
                        tmp_permutation_counter++;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        std::reverse(tmp_vec.begin(), tmp_vec.end());
        matrix=ReturningValues(tmp_vec, matrix,i);
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
BubbleSort::BubbleSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "BubbleSort";
}

void QuickSortMat::QuickSort(std::vector<int>&arr, int start, int end)
{
    if (start < end) {
        int p = Partition(arr, start, end);
        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
    
}
int QuickSortMat::Partition(std::vector<int>& arr, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        tmp_comparison_counter++;
        if (arr[i] < arr[pivot]) {
            tmp_permutation_counter++;
            std::swap(arr[i], arr[j]);
            ++j;
        }
    }
   
        std::swap(arr[j], arr[pivot]);
  
    return j;

}
void QuickSortMat::Sort()
{
   for (int i = 0; i < matrix[0].size(); i++) {
       std::vector<int> tmp_vec = EvenSampling(matrix,i);
       if (tmp_vec.size() >= 2) {
           QuickSort(tmp_vec, 0, static_cast<unsigned int>(tmp_vec.size()) - 1);
       }
       std::reverse(tmp_vec.begin(), tmp_vec.end());
       matrix=ReturningValues(tmp_vec, matrix,i);
   }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
QuickSortMat::QuickSortMat(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "QuickSort";
}