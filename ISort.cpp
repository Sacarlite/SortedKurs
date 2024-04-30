#include "ISort.h"
#include"Algoritm.h"

ISort::ISort(std::vector<std::vector<int>>_matrix) :matrix{ _matrix } {}

void SelectionSort::Sort()
{
    std::string name = "SelectionSort";
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
    int min = 0;
    for (int i = 0; i < matrix.size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix[i]);
        if (tmp_vec.size() > 2) {
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
                    swap(tmp_vec[j], tmp_vec[min]);
                    tmp_permutation_counter++;
                }

            }
            std::reverse(tmp_vec.begin(), tmp_vec.end());
            matrix[i] = ReturningValues(tmp_vec, matrix[i]);
        }
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
std::string SelectionSort::GetName() {
    return name;
}
SelectionSort::SelectionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{}

void InsertionSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
    for (int i = 0; i < matrix.size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix[i]);
        if (tmp_vec.size() > 2) {
            for (int k = 1; k < tmp_vec.size(); k++)
            {

                double temp = tmp_vec[k];
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
            matrix[i] = ReturningValues(tmp_vec, matrix[i]);
        }
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
std::string InsertionSort::GetName() {
    return name;
}
InsertionSort::InsertionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{}

void ShellSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
 
    for (int j = 0; j < matrix.size(); j++)
    {
        std::vector<int> tmp_vec = EvenSampling(matrix[j]);
        if (tmp_vec.size() > 2) {
            for (int gap = tmp_vec.size() / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < tmp_vec.size(); i++) {

                    double temp = tmp_vec[i];
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
        matrix[j] = ReturningValues(tmp_vec, matrix[j]);
}
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
std::string ShellSort::GetName() {
    return name;
}
ShellSort::ShellSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{}

void BubbleSort::Sort()
{
    int tmp_comparison_counter = 0;
    int tmp_permutation_counter = 0;
   
    for (int i = 0; i < matrix.size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix[i]);
        if (tmp_vec.size() > 2) {
            for (int j = 0; j < tmp_vec.size(); j++) {
                bool flag = true;
                for (int k = 0; k < tmp_vec.size() - (j + 1); k++) {
                    tmp_comparison_counter++;
                    if (tmp_vec[k] > tmp_vec[k + 1]) {
                        flag = false;
                        swap(tmp_vec[k], tmp_vec[k + 1]);
                        tmp_permutation_counter++;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        std::reverse(tmp_vec.begin(), tmp_vec.end());
        ReturningValues(tmp_vec, matrix[i]);
    }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
std::string BubbleSort::GetName() {
    return name;
}
BubbleSort::BubbleSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{}

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
            swap(arr[i], arr[j]);
            ++j;
        }
    }
   
        swap(arr[j], arr[pivot]);
  
    return j;

}
void QuickSortMat::Sort()
{
   for (int i = 0; i < matrix.size(); i++) {
       std::vector<int> tmp_vec = EvenSampling(matrix[i]);
       if (tmp_vec.size() > 2) {
           QuickSort(tmp_vec, 0, tmp_vec.size() - 1);
       }
   }
    comparison_counter = tmp_comparison_counter;
    permutation_counter = tmp_permutation_counter;
}
std::string QuickSortMat::GetName() {
    return name;
}
QuickSortMat::QuickSortMat(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{}