#include "quick_sort.h"
#include <stdlib.h>
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Coloca o pivô na posição correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void showQuickSort(int arr[], int n) { 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
    
    if (low == 0 && high == n-1) {
        showQuickSort(arr, n);
    }
}