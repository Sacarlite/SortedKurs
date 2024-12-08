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
    int min = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix,i);
        if (tmp_vec.size() > 1) {
            for (int j = 0; j < tmp_vec.size(); j++)
            {
                min = j; // запоминаем индекс текущего элемента
                // ищем минимальный элемент чтобы поместить на место i-ого
                for (int k = j + 1; k < tmp_vec.size(); k++)  // для остальных элементов после i-ого
                {
                    comparison_counter++;
                    if (tmp_vec[k] > tmp_vec[min]) // если элемент больше минимального,
                        min = k;       // запоминаем его индекс в min
                }
                if (min != j) {//Если индекс рассматриваемого элемента не совпадает с исходным меняем 
                    std::swap(tmp_vec[j], tmp_vec[min]);
                    permutation_counter++;
                }

            }
            ReturningValues(tmp_vec, matrix,i);
        }
    }
}
SelectionSort::SelectionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "SelectionSort";
}
void InsertionSort::Sort()
{
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix, i);
        if (tmp_vec.size() > 1) {
            for (size_t i = 1; i < tmp_vec.size(); ++i) {
                int key = tmp_vec[i];
                int j = i - 1;

                // Сравниваем элементы и сдвигаем их, если они меньше текущего ключа
                while (j >= 0 && tmp_vec[j] < key) {
                    comparison_counter++; // Увеличиваем счётчик сравнений
                    tmp_vec[j + 1] = tmp_vec[j];
                    permutation_counter++;       // Увеличиваем счётчик перестановок
                    j--;
                }
                if (j >= 0) {
                    comparison_counter++; // Учитываем последнее сравнение в условии while
                }
                tmp_vec[j + 1] = key;  // Вставляем ключевой элемент
            }
            ReturningValues(tmp_vec, matrix, i);
        }
    }
}
InsertionSort::InsertionSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "InsertionSort";
}

void ShellSort::Sort()
{
    for (int j = 0; j < matrix[0].size(); j++)
    {
        std::vector<int> tmp_vec = EvenSampling(matrix,j);
        if (tmp_vec.size() > 1) {
            // Начальное значение шага (gap)
            for (int gap = static_cast<unsigned int>(tmp_vec.size()) / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < static_cast<unsigned int>(tmp_vec.size()); ++i) {
                    int key = tmp_vec[i];
                    int j = i;

                    // Сравниваем элементы, разделённые шагом, и перемещаем их
                    while (j >= gap && tmp_vec[j - gap] < key) {
                        comparison_counter++; // Увеличиваем счётчик сравнений
                        tmp_vec[j] = tmp_vec[j - gap];
                        permutation_counter++;       // Увеличиваем счётчик перестановок
                        j -= gap;
                    }

                    if (j >= gap) {
                        comparison_counter++; // Учитываем последнее сравнение в условии while
                    }
                    tmp_vec[j] = key;  // Вставляем ключевой элемент
                }
            }
        }
        ReturningValues(tmp_vec, matrix, j);
}
  
}
ShellSort::ShellSort(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "ShellSort";
}

void BubbleSort::Sort()
{
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> tmp_vec = EvenSampling(matrix, i);
        if (tmp_vec.size() > 1) {
        // Проход по массиву
            for (int i = 0; i < static_cast<unsigned int>(tmp_vec.size()) - 1; i++) {
                // Проход по неотсортированной части массива
                for (int j = 0; j < static_cast<unsigned int>(tmp_vec.size()) - 1 - i; j++) {
                    comparison_counter++;  // увеличиваем счётчик сравнений
                    // Если текущий элемент меньше следующего, меняем их местами
                    if (tmp_vec[j] < tmp_vec[j + 1]) {
                        std::swap(tmp_vec[j], tmp_vec[j + 1]);
                        permutation_counter++;  // увеличиваем счётчик перестановок
                    }
                }
            }
        }
        ReturningValues(tmp_vec, matrix, i);
    }
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
    int pivot = arr[end];  // Ориентируемся на последний элемент как опорный
    int i = start - 1;        // Индекс меньшего элемента

    for (int j = start; j < end; j++) {
        comparison_counter++;

        if (arr[j] >= pivot) {  // Если текущий элемент меньше или равен опорному
            i++;
            SwapElements(arr, i, j);  // Меняем местами
        }
    }
    SwapElements(arr, i + 1, end);  // Меняем опорный элемент на своё место
    return i + 1;  // Индекс опорного элемента
}
void QuickSortMat::SwapElements(std::vector<int>& arr, int i, int j)
{
    if (i != j) {
        permutation_counter++;
    }
    std::swap(arr[i], arr[j]);
}
void QuickSortMat::Sort()
{
   for (int i = 0; i < matrix[0].size(); i++) {
       std::vector<int> tmp_vec = EvenSampling(matrix,i);
       if (tmp_vec.size() > 1) {
           QuickSort(tmp_vec, 0, static_cast<unsigned int>(tmp_vec.size()) - 1);
       }
       ReturningValues(tmp_vec, matrix,i);
   }
}
QuickSortMat::QuickSortMat(std::vector<std::vector<int>>matrix) :ISort{ matrix }
{
    name = "QuickSort";
}