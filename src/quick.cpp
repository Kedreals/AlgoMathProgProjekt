#include "sorting.hpp"

int partition(int* arr, int l, int r)
{
	int p = arr[r]; //pivot
	int t; //help variable for swap
	int i = l - 1; //index for left element
	int j = r; //index for right element

	do
	{
		do ++i; while (arr[i] < p);
		do --j; while (j > 0 && arr[j] > p);

		t = arr[i]; arr[i] = arr[j]; arr[j] = t; //swap
	} while (i < j);

	arr[j] = arr[i]; arr[i] = arr[r]; arr[r] = t;

	return i; //new index of pivot
}

void _quicksort(int* arr, int l, int r)
{
	if (r > l)
	{
		int m = partition(arr, l, r); //determine pivot element 

		_quicksort(arr, l, m - 1);
		_quicksort(arr, m + 1, r);
	}
}


void QuickSort(int n, int* array)
{
	_quicksort(array, 0, n - 1);
}
