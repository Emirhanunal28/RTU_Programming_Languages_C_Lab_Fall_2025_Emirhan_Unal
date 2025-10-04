/*
 * Lab 3, Task 3
 * Student Name, Student ID
 *
 * Implement basic string handling functions.
 * Write your own versions of:
 *   - my_strlen (finds string length)
 *   - my_strcpy (copies string from src to dest)
 *
 * Rules:
 *   - Do not use <string.h> functions for strlen/strcpy.
 *   - Use loops and manual pointer/array access.
 *
 * Example:
 *   char s[] = "hello";
 *   int len = my_strlen(s);   // should return 5
 *
 *   char buffer[100];
 *   my_strcpy(buffer, s);     // buffer now contains "hello"
 */

#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
  char test[] = "Programming in C";
  char copy[100];

  int len = my_strlen(test);
  printf("Length: %d\n", len);  // Expected: 17

  my_strcpy(copy, test);
  printf("Copy: %s\n", copy);  // Expected: Programming in C

  return 0;
}

// count number of characters until the null terminator
int my_strlen(const char *str) {
  int count = 0;
  while (str[count] != '\0') {  // loop until end of string
    count++;
  }
  return count;
}

// copy characters from src to dest, including the null terminator
void my_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {  // copy each character
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';  // add null terminator at the end
}
