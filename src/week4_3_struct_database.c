/*
 * week4_3_struct_database.c
 * Author: [Emirhan Unal]
 * Student ID: [231ADB093]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  struct Student *students =
      (struct Student *)malloc((size_t)n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  printf("Enter data for each student as: <name> <id> <grade>\n");
  printf("(Use names without spaces, e.g., Alice)\n");

  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    if (scanf("%49s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);
      return 1;
    }
  }

  printf("\n%-6s %-12s %-6s\n", "ID", "Name", "Grade");
  printf("-------------------------------\n");

  float sum = 0.0f;
  for (int i = 0; i < n; i++) {
    printf("%-6d %-12s %-6.1f\n", students[i].id, students[i].name,
           students[i].grade);
    sum += students[i].grade;
  }

  printf("-------------------------------\n");
  printf("Average grade: %.2f\n", sum / n);

  free(students);

  // TODO: Allocate memory for n Student structs using malloc

  // TODO: Read student data in a loop

  // TODO: Display all student records in formatted output

  // Optional: Compute average grade or find top student

  // TODO: Free allocated memory

  return 0;
}
