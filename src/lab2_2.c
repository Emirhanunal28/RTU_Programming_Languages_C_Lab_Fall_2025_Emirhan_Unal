#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    long long result = 1;

    // compute factorial iteratively (no recursion)
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;   // <-- factorial burada biter
}

int main(void) {
    int n;

    // Ask user for input
    printf("Enter a non-negative integer n: ");
    if (scanf("%d", &n) != 1) {
        printf("Input error.\n");
        return 1;
    }

    // Validate input
    if (n < 0) {
        printf("Error: n must be non-negative.\n");
        return 1;
    }

    // Call factorial and print result
    long long result = factorial(n);
    printf("%d! = %lld\n", n, result);

    return 0;
}
