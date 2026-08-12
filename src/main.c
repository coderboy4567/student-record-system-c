#include <stdio.h>
#include "../include/student.h"

#define MAX_STUDENTS 100
#define FILE_PATH "../data/students.txt"

void displayMenu(void);
void addStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);
int searchStudent(struct Student students[], int count, int rollNumber);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void saveToFile(struct Student students[], int count);
int loadFromFile(struct Student students[]);
void sortStudents(struct Student students[], int count);
void showStatistics(struct Student students[], int count);

int main(void) {
    int choice;
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    studentCount = loadFromFile(students);
    printf("Loaded %d student(s) from file.\n", studentCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3: {
                int roll;
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                int index = searchStudent(students, studentCount, roll);
                if (index == -1) {
                    printf("Student not found!\n");
                } else {
                    printf("Found -> Roll: %d, Name: %s, Marks: %.2f\n",
                           students[index].rollNumber,
                           students[index].name,
                           students[index].marks);
                }
                break;
            }
            case 4:
                updateStudent(students, studentCount);
                break;
            case 5:
                deleteStudent(students, &studentCount);
                break;
            case 7:
                sortStudents(students, studentCount);
                printf("Students sorted by marks (descending).\n");
                break;
            case 8:
                showStatistics(students, studentCount);
                break;
            case 6:
                saveToFile(students, studentCount);
                printf("Data saved. Exiting... Goodbye!\n");
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
    printf("7. Sort Students (by Marks)\n");
    printf("8. Show Statistics\n");
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
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    int index = searchStudent(students, count, roll);

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", students[index].name);

    printf("Enter new Marks: ");
    scanf("%f", &students[index].marks);

    printf("Student updated successfully!\n");
}

void deleteStudent(struct Student students[], int *count) {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

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

void saveToFile(struct Student students[], int count) {
    FILE *file = fopen(FILE_PATH, "w");

    if (file == NULL) {
        printf("Error: Could not open file to save data!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d|%s|%.2f\n",
                students[i].rollNumber,
                students[i].name,
                students[i].marks);
    }

    fclose(file);
}

int loadFromFile(struct Student students[]) {
    FILE *file = fopen(FILE_PATH, "r");

    if (file == NULL) {
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d|%49[^|]|%f\n",
                   &students[count].rollNumber,
                   students[count].name,
                   &students[count].marks) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

void sortStudents(struct Student students[], int count) {
    // Bubble Sort - marks ke hisaab se descending order (highest pehle)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void showStatistics(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to show statistics for.\n");
        return;
    }

    float total = 0;
    float highest = students[0].marks;
    float lowest = students[0].marks;

    for (int i = 0; i < count; i++) {
        total += students[i].marks;

        if (students[i].marks > highest) {
            highest = students[i].marks;
        }
        if (students[i].marks < lowest) {
            lowest = students[i].marks;
        }
    }

    float average = total / count;

    printf("\n----- STATISTICS -----\n");
    printf("Total Students : %d\n", count);
    printf("Average Marks  : %.2f\n", average);
    printf("Highest Marks  : %.2f\n", highest);
    printf("Lowest Marks   : %.2f\n", lowest);
}