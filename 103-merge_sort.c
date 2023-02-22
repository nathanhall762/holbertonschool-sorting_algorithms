#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= right) {
        temp[k] = array[j];
        k++;
        j++;
    }

    for (i = left; i <= right; i++) {
        array[i] = temp[i];
    }
}

void merge_sort_helper(int *array, int *temp, int left, int right) {
    int mid;
    if (left >= right) {
        return;
    }

	mid = (left + right) / 2;
    merge_sort_helper(array, temp, left, mid);
    merge_sort_helper(array, temp, mid + 1, right);
    merge(array, temp, left, mid, right);
}

void merge_sort(int *array, size_t size) {
    int *temp = (int *) malloc(sizeof(int) * size);
    merge_sort_helper(array, temp, 0, size - 1);
    free(temp);
}
