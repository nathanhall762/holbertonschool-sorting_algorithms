#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge(int *array, int low, int mid, int high);
void sort(int *array, int low, int high);
void merge_sort(int *array, size_t size);
int *malloc_array(int size);
void print_all(int *array, int high, int low, int *temp_left, int *temp_right,
int left_len, int right_len);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *array, int sub_array_size, size_t size, int i);
void radix_sort(int *array, size_t size);



#endif
