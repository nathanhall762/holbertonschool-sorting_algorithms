#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using merge sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array to be sorted
 *
 * This function takes an array of integers and its size as input and sorts
 * the array in ascending order using the merge sort algorithm. The merge sort
 * algorithm is a divide-and-conquer algorithm that recursively splits the
 * input array into smaller subarrays until each subarray contains only one
 * element, then merges these subarrays back together in sorted order.
 */
void merge_sort(int *array, size_t size)
{
	int len = (int)size;
	int *A = array;
	int *B = malloc(sizeof(int) * len);
	int i;

	for (i = 0; i < len; i++)
		B[i] = A[i];

	split(B, A, 0, len);
	free(B);
}

/**
 * split - recursively splits an array into trivially sorted, single-member
 * subarrays.
 *
 * @A: first array
 * @B: temporary array
 * @left: left index of subarray
 * @right: right index of subarray
 *
 * This function takes two arrays, A and B, and two indices, left and right,
 * as input. It recursively splits the subarray of A between left and right
 * into smaller subarrays until each subarray contains only one element. The
 * function then calls merge_help to merge these subarrays back together in
 * sorted order.
 */
void split(int *A, int *B, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	split(B, A, left, mid);
	split(B, A, mid, right);

	merge_help(A, B, left, mid, right);

	printf("Merging...\n[left]: ");
	print_subarray(A, left, mid);
	printf("[right]: ");
	print_subarray(A, mid, right);
	printf("[Done]: ");
	print_subarray(B, left, right);
}

/**
 * merge_help - merges two sorted arrays
 *
 * @A: first array to merge
 * @B: second array to merge
 * @left: start of first subarray
 * @mid: start of right subarray
 * @right: end of array
 *
 * This function takes two arrays, A and B, and three indices, left, mid,
 * and right, as input. It merges the two sorted subarrays of A between left
 * and mid and between mid and right into a single sorted subarray in B between
 * left and right.
 */
void merge_help(int *A, int *B, int left, int mid, int right)
{
	int aPos = left;
	int bPos = mid;
	int i;

	for (i = left; i < right; i++)
		if (aPos < mid && (bPos >= right || A[aPos] <= A[bPos]))
			B[i] = A[aPos++];
		else
			B[i] = A[bPos++];
}

/**
 * print_subarray - prints a subarray given start and end
 *
 * @arr: array containing subarray to print
 * @start: first index to print
 * @end: index to print to
 *
 * This function takes an array and two indices, start and end, as input. It
 * prints the elements of the subarray of arr between start and end.
 */
void print_subarray(int *arr, int start, int end)
{
	int i;

	for (i = start; i < end - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[end - 1]);
}
