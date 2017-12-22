#ifndef _SORTING_HPP_
#define _SORTING_HPP_

void InsertionSort(int n, int* array);
void QuickSort(int n, int* array);
void HeapSort(int n, int* array);

void ReadFile(const char* filename, int** array, int& n);
void WriteFile(const char* filename, const int* array, int n);
#endif
