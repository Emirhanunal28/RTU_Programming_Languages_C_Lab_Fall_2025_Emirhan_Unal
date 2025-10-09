#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int *arr;
  int sum = 0;
  double avg;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  avg = (double)sum / n;

  printf("\nSum = %d\n", sum);
  printf("Average = %.2f\n", avg);

  free(arr);
  return 0;
}
