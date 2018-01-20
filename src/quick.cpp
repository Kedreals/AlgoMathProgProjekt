#include "sorting.hpp"

//swaps two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int* arr, int l, int r)
{
	int p = arr[r]; //pivot
	int t;	
	int i = l - 1, j = r;

	do
	{
		do ++i; while (arr[i] < p);
		do --j; while (j >= 0 && arr[i] > p);

		swap(&arr[i], &arr[j]);
	} while (i < j);

	swap(&arr[i + 1], &arr[r]);

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
