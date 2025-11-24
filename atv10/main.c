#include "bubble_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include <stdio.h>
#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Bubble Sort: ");
    bubbleSort(arr, n);

    printf("Insertion Sort: ");
    insertionSort(arr1, n);

    printf("Quick Sort: ");
    quickSort(arr2, 0, n-1, n);

    printf("Selection Sort: ");
    selectionSort(arr3, n);
}