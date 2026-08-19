#include <stdio.h>
#include "../include/student.h"

void sortStudents(struct Student students[], int count) {
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

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInt(const char *prompt) {
    int value;
    printf("%s", prompt);

    while (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

float getValidFloat(const char *prompt) {
    float value;
    printf("%s", prompt);

    while (scanf("%f", &value) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

char getGrade(float marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 75) {
        return 'B';
    } else if (marks >= 60) {
        return 'C';
    } else if (marks >= 40) {
        return 'D';
    } else {
        return 'F';
    }
}