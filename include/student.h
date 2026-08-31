#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

/* File paths used by the program. */
#define FILE_PATH "../data/students.txt"
#define BACKUP_PATH "../data/backup.txt"
#define CSV_PATH "../data/students.csv"

/* Store basic information about a student. */
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

/* Menu and screen functions. */
void displayMenu(void);
void clearScreen(void);
void pauseScreen(void);
int login(void);

/* Functions for managing students. */
void addStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);

int searchStudent(
    struct Student students[],
    int count,
    int rollNumber
);

int searchStudentByName(
    struct Student students[],
    int count,
    const char *name
);

void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

/* Functions for saving and loading student data. */
void saveToFile(struct Student students[], int count);
int loadFromFile(struct Student students[]);
void exportToCSV(struct Student students[], int count);

/* Sorting and statistics functions. */
void sortStudents(struct Student students[], int count);
void sortByName(struct Student students[], int count);
void sortByRoll(struct Student students[], int count);
void showStatistics(struct Student students[], int count);
char getGrade(float marks);

/* Input handling functions. */
void clearInputBuffer(void);
int getValidInt(const char *prompt);
float getValidFloat(const char *prompt);
float getValidMarks(const char *prompt);

#endif