#pragma once
#include "Check.h"
#include "ISort.h"
#include <iomanip>
#include <ctime>

std::vector<int> EvenSampling(std::vector<int>);//TODO сделать функцию фильтрации положительных значений
std::vector<int> ReturningValues(std::vector<int>, std::vector<int>);
template <class T> void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}

