#include "sort.h"

void merge(int *array, int low, int mid, int high)
{
	int left_idx, right_idx, array_idx;
	int left_len = mid - low + 1;
	int right_len = high - mid;
	int *temp_left = malloc_array(left_len);
	int *temp_right = malloc_array(right_len);

	for (left_idx = 0; left_idx < left_len; left_idx++)
		temp_left[left_idx] = array[low + left_idx];
	for (right_idx = 0; right_idx < right_len; right_idx++)
		temp_right[right_idx] = array[mid + right_idx + 1];
	left_idx = 0, right_idx = 0, array_idx = low;
	while (left_idx < left_len && right_idx < right_len)
	{
		if (temp_left[left_idx] <= temp_right[right_idx])
		{
			array[array_idx] = temp_left[left_idx];
			left_idx++;
		}
		else
		{
			array[array_idx] = temp_right[right_idx];
			right_idx++;
		}
		array_idx++;
	}
	while (left_idx < left_len)
	{
		array[array_idx] = temp_left[left_idx];
		left_idx++;
		array_idx++;
	}
	while (right_idx < right_len)
	{
		array[array_idx] = temp_right[right_idx];
		right_idx++;
		array_idx++;
	}
	printf("Merging...\n[left]: ");
	print_array(temp_left, left_len);
	printf("[right]: ");
	print_array(temp_right, right_len);
	printf("[Done]: ");
	array += low;
	print_array(array, high - low + 1);
	array -= low;
	free(temp_left);
	free(temp_right);
}

void sort(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;

		sort(array, low, mid);
		sort(array, mid + 1, high);

		merge(array, low, mid, high);
	}
}

void merge_sort(int *array, size_t size)
{
	sort(array, 0, size - 1);
}

int *malloc_array(int size)
{
	int *array;

	array = malloc(size * sizeof(int));
	return (array);
}
