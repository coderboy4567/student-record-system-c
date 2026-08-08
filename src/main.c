#include <stdio.h>
#include "../include/student.h"

#define MAX_STUDENTS 100

void displayMenu(void);
void addStudent(struct Student students[], int *count);

int main(void) {
    int choice;
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu(void) {
    printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached!\n");
        return;
    }

    struct Student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}