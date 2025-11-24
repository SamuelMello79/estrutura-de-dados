#include "selection_sort.h"
#include <stdio.h>
#include <stdio.h>

void showSelectionSort(int arr[], int n) { 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Encontra o menor elemento
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    showSelectionSort(arr, n);
}