/*
 * week4_1_dynamic_array.c
 * Author: [Emirhan Unal]
 * Student ID: [231ADB093]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int *arr = NULL;
  int sum = 0;
  double avg = 0.0;

  // Read array size
  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // Allocate memory
  arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Read values
  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
    sum += arr[i];
  }

  // Compute average
  avg = (double)sum / n;

  // Print results
  printf("\nSum = %d\n", sum);
  printf("Average = %.2f\n", avg);

  // Free memory
  free(arr);
  return 0;
}
