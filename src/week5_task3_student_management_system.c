// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
  char name[NAME_LEN];
  int id;
  float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice;

  // TODO: Load existing data from file using load_students()
  count = load_students(students);

  do {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");

    if (scanf("%d", &choice) != 1) {
      // Clear invalid input
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      printf("Invalid input. Try again.\n");
      continue;
    }

    switch (choice) {
      case 1:
        // TODO: Call list_students() to display all records
        list_students(students, count);
        break;

      case 2:
        // TODO: Call add_student() to add a new record
        add_student(students, &count);
        break;

      case 3:
        // TODO: Call save_students() to save data and exit
        save_students(students, count);
        printf("Data saved. Goodbye!\n");
        break;

      default:
        printf("Invalid option. Try again.\n");
    }

  } while (choice != 3);

  return 0;
}

// TODO: Implement load_students()
// Opens DATA_FILE for reading, reads records until EOF,
// stores them in arr[], and returns the number of records loaded.
int load_students(Student arr[]) {
  FILE *fp = fopen(DATA_FILE, "r");
  int count = 0;

  if (fp == NULL) {
    // File does not exist yet, start with empty list
    return 0;
  }

  while (count < MAX_STUDENTS &&
         fscanf(fp, "%d %49s %f", &arr[count].id, arr[count].name,
                &arr[count].gpa) == 3) {
    count++;
  }

  fclose(fp);
  return count;
}

// TODO: Implement save_students()
// Opens DATA_FILE for writing, saves all students from arr[],
// and closes the file.
void save_students(Student arr[], int count) {
  FILE *fp = fopen(DATA_FILE, "w");
  if (fp == NULL) {
    printf("Error opening %s for writing.\n", DATA_FILE);
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(fp, "%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }

  fclose(fp);
}

// TODO: Implement add_student()
// Reads new student data from the user and appends it to the array.
void add_student(Student arr[], int *count) {
  if (*count >= MAX_STUDENTS) {
    printf("Array full. Cannot add more students.\n");
    return;
  }

  Student s;

  printf("Enter name: ");
  if (scanf("%49s", s.name) != 1) {
    printf("Invalid name.\n");
    return;
  }

  printf("Enter ID: ");
  if (scanf("%d", &s.id) != 1) {
    printf("Invalid ID.\n");
    return;
  }

  printf("Enter GPA: ");
  if (scanf("%f", &s.gpa) != 1) {
    printf("Invalid GPA.\n");
    return;
  }

  arr[*count] = s;
  (*count)++;

  printf("Student added successfully!\n");
}

// TODO: Implement list_students()
// Prints all loaded students in a formatted table.
void list_students(Student arr[], int count) {
  if (count == 0) {
    printf("No students yet.\n");
    return;
  }

  printf("\n%-4s %-6s %-20s %-5s\n", "#", "ID", "Name", "GPA");
  for (int i = 0; i < count; i++) {
    printf("%-4d %-6d %-20s %.2f\n", i + 1, arr[i].id, arr[i].name, arr[i].gpa);
  }
}
