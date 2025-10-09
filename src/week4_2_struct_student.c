/*
 * week4_2_struct_student.c
 * Author: [Emirhan Unal]
 * Student ID: [231ADB093]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and
 * grade. Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student s1, s2;

  /* Assign values (using dot operator and strcpy for name) */
  strcpy(s1.name, "Alice Johnson");
  s1.id = 1001;
  s1.grade = 9.1f;

  strcpy(s2.name, "Bob Smith");
  s2.id = 1002;
  s2.grade = 8.7f;

  /* Print in a readable, labeled format */
  printf("Student 1: Name: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id,
         s1.grade);
  printf("Student 2: Name: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id,
         s2.grade);

  return 0;
}
