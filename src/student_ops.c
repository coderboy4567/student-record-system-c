#include <stdio.h>
#include <string.h>
#include "../include/student.h"

/**
 * Naya student ko array mein add karta hai.
 * User se roll number, name, aur marks input leta hai.
 * Duplicate roll number ko reject karta hai.
 *
 * @param students Array jisme student add hoga
 * @param count Pointer jo total student count track karta hai
 */
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

/**
 * Saare students ko table format mein print karta hai, grade ke saath.
 * @param students Student array
 * @param count Total students ki sankhya
 */
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

/**
 * Roll number se student ko dhoondta hai.
 * @param students Student array
 * @param count Total students ki sankhya
 * @param rollNumber Dhoondne wala roll number
 * @return Match mile to index, warna -1
 */
int searchStudent(struct Student students[], int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

/**
 * Roll number se student dhoondke uski name aur marks update karta hai.
 * @param students Student array
 * @param count Total students ki sankhya
 */
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

/**
 * Roll number se student dhoondke array se delete karta hai (shift karke).
 * @param students Student array
 * @param count Pointer to current student count
 */
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

/**
 * Naam se student ko dhoondta hai (exact match, case-sensitive).
 * @param students Student array
 * @param count Total students ki sankhya
 * @param name Dhoondne wala naam
 * @return Match mile to index, warna -1
 */
int searchStudentByName(struct Student students[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}