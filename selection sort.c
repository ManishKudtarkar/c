#include <stdio.h>

int i, j, size;
int array[100];

int main() {
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  printf("Enter the elements:\n");
  for (i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  
  for (i = 0; i < size - 1; i++) {
    int min_index = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
   
    int temp = array[min_index];
    array[min_index] = array[i];
    array[i] = temp;
  }

  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
