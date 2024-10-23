#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "sorting/sorting.h"

#define N 1000

int main() {
    srand(time(NULL));
    int* arr = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) { arr[i] = rand() % 10000; }

    quick_sort_hoare(arr, 0, N - 1);

    for(int i = 1; i < N; i++) {
        assert(arr[i] >= arr[i-1]);
        printf("%d\n", arr[i]);
    }
    return 0;
}
