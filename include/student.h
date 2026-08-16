#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define FILE_PATH "../data/students.txt"

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Menu
void displayMenu(void);

// Student operations
void addStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);
int searchStudent(struct Student students[], int count, int rollNumber);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

// File operations
void saveToFile(struct Student students[], int count);
int loadFromFile(struct Student students[]);

// Utilities
void sortStudents(struct Student students[], int count);
void showStatistics(struct Student students[], int count);
void clearInputBuffer(void);
int getValidInt(const char *prompt);
float getValidFloat(const char *prompt);

#endif