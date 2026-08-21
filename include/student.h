#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define FILE_PATH "../data/students.txt"
#define BACKUP_PATH "../data/backup.txt"

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
int searchStudentByName(struct Student students[], int count, const char *name);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

// File operations
void saveToFile(struct Student students[], int count);
int loadFromFile(struct Student students[]);

// Utilities
void sortStudents(struct Student students[], int count);
void sortByName(struct Student students[], int count);
void sortByRoll(struct Student students[], int count);
void showStatistics(struct Student students[], int count);
char getGrade(float marks);
void clearInputBuffer(void);
int getValidInt(const char *prompt);
float getValidFloat(const char *prompt);

#endif