#include "merge_sort.h"

void merge_sort(int* arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right) {
    int i, j, k, l1 = mid - left + 1, l2 = right - mid;

    // temporary arrays to store original content of the subarrays
    int temp1[l1];
    int temp2[l2];

    // fill the temporary arrays
    for(i = 0; i < l1; i++) { temp1[i] = arr[left + i]; }
    for(j = 0; j < l2; j++) { temp2[j] = arr[mid + j + 1]; }

    // merge the temporary arrays back into the original array
    i = 0, j = 0, k = left;
    while(i < l1 && j < l2) { // untill one of the two subarray ends
        if(temp1[i] < temp2[j]) {
            arr[k] = temp1[i];
            i++;
        }
        else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    // append any remaining elements of the first subarray
    while(i < l1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    // append any remaining elements of the second subarray
    while(j < l2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
