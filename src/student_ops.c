#include <stdio.h>
#include <string.h>
#include "../include/student.h"

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached!\n");
        return;
    }

    struct Student newStudent;

    newStudent.rollNumber = getValidInt("Enter Roll Number: ");

    if (searchStudent(students, *count, newStudent.rollNumber) != -1) {
        printf("Error: Roll Number already exists!\n");
        return;
    }

    char nameBuffer[50];
    do {
    printf("Enter Name: ");
    scanf(" %[^\n]", nameBuffer);
    if (nameBuffer[0] == '\0') {
        printf("Name cannot be empty!\n");
    }
    } while (nameBuffer[0] == '\0');
    strcpy(newStudent.name, nameBuffer);

   newStudent.marks = getValidMarks("Enter Marks: ");

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

void viewStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students added yet.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-5s\n", "Roll", "Name", "Marks", "Grade");
    printf("------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        char grade = getGrade(students[i].marks);
        printf("%-5d %-20s %-10.2f %-5c\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks,
               grade);
    }
}

int searchStudent(struct Student students[], int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

void updateStudent(struct Student students[], int count) {
    int roll = getValidInt("Enter Roll Number to update: ");

    int index = searchStudent(students, count, roll);

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", students[index].name);

    students[index].marks = getValidMarks("Enter new Marks: ");

    printf("Student updated successfully!\n");
}

void deleteStudent(struct Student students[], int *count) {
    int roll = getValidInt("Enter Roll Number to delete: ");

    int index = searchStudent(students, *count, roll);

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("Student deleted successfully!\n");
}

int searchStudentByName(struct Student students[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}