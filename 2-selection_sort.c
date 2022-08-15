#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, tmp, j;

	for(i = 0; i + 1 < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
