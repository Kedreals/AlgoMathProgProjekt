#ifndef _SORTING_HPP_
#define _SORTING_HPP_

/** \brief sorts the array via Insertionsort
 */
void InsertionSort(int n, int* array);
/** \brief sorts the array via Quicksort
 */
void QuickSort(int n, int* array);
/** \brief sorts the array via Heapsort
 */
void HeapSort(int n, int* array);

/** \brief Reads the array \a array with length \a n from the file \a filename
 */
void ReadFile(const char* filename, int** array, int& n);
/** \brief Writes the array \a array with length \a n to the file \a filename but as _sortiert

    if the filename is instanzXY.txt then the wiritten file is instanzXY_sortier.txt
    it is implicitly thought that the filename ends with a 4 character long ending eg .txt
 */
void WriteFile(const char* filename, const int* array, int n);
#endif
