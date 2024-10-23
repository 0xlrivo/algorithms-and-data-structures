/* SPDX-License-Identifier: GPL-2.0 */

/**
 * @brief sorts an array using the merge sort algorithm
 * @param arr the array to sort
 * @param left starting index
 * @param right ending index
 */
void merge_sort(int* arr, int left, int right);

/**
 * @brief merges two sorted sub-arrays [left...mid] and [mid+1...end]
 * @param arr pointer to the array containing the two subarrays
 * @param left starting index of the first subarray
 * @param mid middle index that separates the two subarrays
 * @param right final index of the second subarray
 */
void merge(int* arr, int left, int mid, int right);
