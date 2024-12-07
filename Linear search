#include <stdio.h>

int main() {
    char ch;
    int arr[50], n, i, j;
    
    // Input the number of elements
    printf("\nHow many elements do you want to enter: ");
    scanf("%d", &n);
    
    // Input array elements
    for (i = 0; i < n; i++) {
        printf("\nEnter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    // Input the element to search
    printf("\nEnter the element to be searched: ");
    scanf("%d", &j);
    
    // Perform linear search
    for (i = 0; i < n; i++) {
        if (j == arr[i]) {
            printf("\n%d found at position %d\n", j, i + 1);
            break;
        }
    }
    
    // If element is not found
    if (i == n) {
        printf("\nItem %d not found in the array\n", j);
    }
    
    return 0;
}
