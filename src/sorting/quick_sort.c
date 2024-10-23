#include "quick_sort.h"

void swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int partition_lomuto(int* arr, int left, int right) {
    int pivot = arr[right]; // take the last element as the pivot
    int i = left - 1;

    // loop through the non-pivot elements
    for(int j = left; j <= right - 1; j++) {
        if(arr[j] <= pivot) { // if this element is less than the pivot
            i++; // increment lower-partition pointer
            swap(&arr[i], &arr[j]);
        }
    }

    // put the pivot between the two partitions
    swap(&arr[i+1], &arr[right]);
    // return the new pivot's index
    return i + 1;
}

/// more efficient than lomuto because it traverses the array in both directions
/// simultaneously, resulting in less swaps on average
int partition_hoare(int* arr, int left, int right) {
    int pivot = arr[left]; // take the first element as the pivot
    int i = left - 1, j = right + 1;

    while(1) {
        i++;
        while(arr[i] < pivot) { i++; }

        j--;
        while(arr[j] > pivot) { j--; }

        // if the pointers crossed, then this partition is sorted
        if(i >= j) return j;

        swap(&arr[i], &arr[j]);
    }
}

/// quick sort implementation using the lomuto partitioning algorithm
void quick_sort_lomuto(int* arr, int left, int right) {
    if(left < right) {
        int pivot = partition_lomuto(arr, left, right);
        quick_sort_lomuto(arr, left, pivot - 1);
        quick_sort_hoare(arr, pivot + 1, right);
    }
};

/// quick sort implementation using the hoare partitioning algorihtm
void quick_sort_hoare(int *arr, int left, int right) {
    if(left < right) {
        int pivot = partition_hoare(arr, left, right);
        quick_sort_hoare(arr, left, pivot);
        quick_sort_hoare(arr, pivot + 1, right);
    }
}
