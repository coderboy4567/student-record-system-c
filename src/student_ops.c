#include <stdio.h>
#include <string.h>
#include "../include/student.h"

/* Add a new student to the student array. */
void addStudent(struct Student students[], int *count)
{
    /* Check whether the maximum student limit is reached. */
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached!\n");
        return;
    }

    struct Student newStudent;

    newStudent.rollNumber = getValidInt("Enter Roll Number: ");

    /* Check if the roll number already exists. */
    if (searchStudent(students, *count, newStudent.rollNumber) != -1) {
        printf("Error: Roll Number already exists!\n");
        return;
    }

    char nameBuffer[50];

    /* Keep asking until the user enters a name. */
    do {
        printf("Enter Name: ");

        fgets(nameBuffer, sizeof(nameBuffer), stdin);
        nameBuffer[strcspn(nameBuffer, "\n")] = '\0';

        if (nameBuffer[0] == '\0') {
            printf("Name cannot be empty!\n");
        }

    } while (nameBuffer[0] == '\0');

    strcpy(newStudent.name, nameBuffer);

    /* Get marks and make sure they are between 0 and 100. */
    newStudent.marks = getValidMarks("Enter Marks: ");

    /* Add the new student and increase the count. */
    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

/* Display all students in a table with their grades. */
void viewStudents(struct Student students[], int count)
{
    if (count == 0) {
        printf("No students added yet.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-5s\n",
           "Roll", "Name", "Marks", "Grade");

    printf("------------------------------------------\n");

    /* Display each student's details. */
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10.2f %-5c\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks,
               getGrade(students[i].marks));
    }
}

/* Search for a student using their roll number. */
int searchStudent(
    struct Student students[],
    int count,
    int rollNumber
)
{
    /* Check each student until the roll number is found. */
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }

    return -1;
}

/* Update a student's name and marks using their roll number. */
void updateStudent(struct Student students[], int count)
{
    int roll = getValidInt("Enter Roll Number to update: ");
    int index = searchStudent(students, count, roll);

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    char nameBuffer[50];

    /* Ask for a new name. */
    do {
        printf("Enter new Name: ");

        fgets(nameBuffer, sizeof(nameBuffer), stdin);
        nameBuffer[strcspn(nameBuffer, "\n")] = '\0';

        if (nameBuffer[0] == '\0') {
            printf("Name cannot be empty!\n");
        }

    } while (nameBuffer[0] == '\0');

    strcpy(students[index].name, nameBuffer);

    /* Ask for new marks and validate the range. */
    students[index].marks = getValidMarks("Enter new Marks: ");

    printf("Student updated successfully!\n");
}

/* Delete a student using their roll number. */
void deleteStudent(struct Student students[], int *count)
{
    int roll = getValidInt("Enter Roll Number to delete: ");
    int index = searchStudent(students, *count, roll);

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    /* Shift the remaining students one position to the left. */
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("Student deleted successfully!\n");
}

/* Search for a student using their exact name. */
int searchStudentByName(
    struct Student students[],
    int count,
    const char *name
)
{
    /* Compare the given name with each student's name. */
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}