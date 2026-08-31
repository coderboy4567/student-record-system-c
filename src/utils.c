#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/student.h"

/* Sort students by marks from highest to lowest using Bubble Sort. */
void sortStudents(struct Student students[], int count)
{
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

/* Calculate and display student statistics. */
void showStatistics(struct Student students[], int count)
{
    if (count == 0) {
        printf("No students to show statistics for.\n");
        return;
    }

    float total = 0.0f;
    float highest = students[0].marks;
    float lowest = students[0].marks;

    /* Calculate total, highest, and lowest marks. */
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

/* Remove unwanted characters left in the input buffer. */
void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

/* Take an integer input and handle invalid input. */
int getValidInt(const char *prompt)
{
    int value;

    printf("%s", prompt);

    while (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }

    clearInputBuffer();

    return value;
}

/* Take a floating-point input and handle invalid input. */
float getValidFloat(const char *prompt)
{
    float value;

    printf("%s", prompt);

    while (scanf("%f", &value) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }

    clearInputBuffer();

    return value;
}

/* Return the grade according to the student's marks. */
char getGrade(float marks)
{
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 75) {
        return 'B';
    } else if (marks >= 60) {
        return 'C';
    } else if (marks >= 40) {
        return 'D';
    }

    return 'F';
}

/* Sort students by name in alphabetical order. */
void sortByName(struct Student students[], int count)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {

            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

/* Sort students by roll number in ascending order. */
void sortByRoll(struct Student students[], int count)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {

            if (students[j].rollNumber > students[j + 1].rollNumber) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

/* Clear the terminal screen according to the operating system. */
void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* Wait for the user to press Enter before continuing. */
void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}

/* Take marks as input and make sure they are between 0 and 100. */
float getValidMarks(const char *prompt)
{
    float value;

    do {
        value = getValidFloat(prompt);

        if (value < 0 || value > 100) {
            printf(
                "Invalid marks! Marks must be between 0 and 100.\n"
            );
        }

    } while (value < 0 || value > 100);

    return value;
}

/* Check the username and password with a maximum of 3 attempts. */
int login(void)
{
    char username[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0) {

        printf("Username: ");
        scanf(" %19s", username);

        printf("Password: ");
        scanf(" %19s", password);

        /* Check whether the entered credentials are correct. */
        if (strcmp(username, "admin") == 0 &&
            strcmp(password, "admin123") == 0) {

            printf("Login successful!\n");
            clearInputBuffer();

            return 1;
        }

        attempts--;

        printf(
            "Invalid credentials! Attempts left: %d\n",
            attempts
        );
    }

    clearInputBuffer();

    return 0;
}