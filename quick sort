#include <stdio.h>

// Function to partition the array
int partition(int a[], int start, int end) {
    int pivot = a[end];  // Pivot element
    int i = start - 1;   // Index for smaller element

    for (int j = start; j <= end - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap the pivot element with the element at (i+1)
    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;

    return (i + 1);
}

// Quick Sort recursive function
void quick(int a[], int start, int end) {
    if (start < end) {
        int p = partition(a, start, end); // Partition index
        quick(a, start, p - 1);           // Sort elements before partition
        quick(a, p + 1, end);             // Sort elements after partition
    }
}

// Function to print the array
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int a[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    printArr(a, n);

    quick(a, 0, n - 1);

    printf("After sorting array elements are - \n");
    printArr(a, n);

    return 0;
}
