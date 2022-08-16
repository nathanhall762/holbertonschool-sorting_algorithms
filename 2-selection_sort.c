#include "sort.h"

/**
*selection_sort - sorts with selection
*@array: array to sort
*@size: size of array to be sorted
*/

void selection_sort(int *array, size_t size)
{
	size_t i, tmp, j, lowindex;
	int low;

	for (i = 0; i + 1 < size; i++)
	{
		low = array[i + 1];
		lowindex = i + 1;
		for (j = i + 1; j < size; j++)
		{
			if (low > array[j])
			{
				low = array[j];
				lowindex = j;
			}
		}
		if (array[i] > low)
		{
			tmp = array[i];
			array[i] = array[lowindex];
			array[lowindex] = tmp;
			print_array(array, size);
		}
	}
}
