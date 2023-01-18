#include "sort.h"

/**
*sort_quick - recursive quick sort function
*@array: pointer to array to sort
*@low: low value of partition to sort
*@high: high value of partition to sort
*@size: size of full array
*/

void sort_quick(int *array, int low, int high, size_t size)
{
	int i = low, j = low, pivot = array[high], tmp;

	if (low >= high)
		return;

	for (; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				j++;
				print_array(array, size);
			}
			else
				j++;
		}
	}
	if (j != high)
	{
		tmp = array[high];
		array[high] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}

	sort_quick(array, low, j - 1, size);
	sort_quick(array, j + 1, high, size);
}

/**
*quick_sort - sorts stuff but quickly
*@array: pointer to array
*@size: size of array
*/

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (size == 0)
		return;
	sort_quick(array, low, high, size);
}
