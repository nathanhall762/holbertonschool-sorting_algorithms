#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	int temp, unsorted = 1;
	size_t i, sizecp = size;

	while (unsorted)
	{
		unsorted = 0;
		for (i = 0; i + 1 < sizecp; i++)
		{
			if (array[i] > array[i + 1])
			{
				unsorted = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		sizecp--;
	}
}
