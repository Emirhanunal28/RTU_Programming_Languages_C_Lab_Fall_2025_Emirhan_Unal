#include <stdio.h>

/*
    Task:
    Write a function `int sum_to_n(int n)` that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  int n;

  // Ask user for n
  printf("Enter a positive integer n: ");
  scanf("%d", &n);

  // Check if n is valid
  if (n < 1) {
    printf("Error: n must be at least 1.\n");
  } else {
    // Call sum_to_n and print result
    int result = sum_to_n(n);
    printf("The sum of integers from 1 to %d is: %d\n", n, result);
  }

  return 0;
}
