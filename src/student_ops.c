#include <stdio.h>
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

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);

    newStudent.marks = getValidFloat("Enter Marks: ");

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

void viewStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students added yet.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s\n", "Roll", "Name", "Marks");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10.2f\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks);
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

    students[index].marks = getValidFloat("Enter new Marks: ");

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