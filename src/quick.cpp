#include "sorting.hpp"

int partition(int* arr, int l, int r)
{
	int p = arr[r]; //pivot
	int t;	
	int i = l - 1, j = r;

	do
	{
		do ++i; while (arr[i] < p);
		do --j; while (j >= 0 && arr[i] > p);

		t = arr[i]; arr[i] = arr[j]; arr[j] = t;
	} while (i < j);

	arr[j] = arr[i]; arr[i] = arr[r]; arr[r] = t;

	return i;	//new index of pivot
}

void _quicksort(int* arr, int l, int r)
{
	if(r>l)
	{
		int m = partition(arr, l, r);

		_quicksort(arr, l, m - 1);
		_quicksort(arr, m + 1, r);
	}
}


void QuickSort(int n, int* array)
{
	_quicksort(array, 0, n - 1);
}
