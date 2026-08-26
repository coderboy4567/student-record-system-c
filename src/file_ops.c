#include <stdio.h>
#include "../include/student.h"

/**
 * Student data ko file mein save karta hai, saath hi backup copy bhi banata hai.
 * @param students Student array
 * @param count Total students ki sankhya
 */
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

    // Backup copy bhi bana rahe hain
    FILE *backup = fopen(BACKUP_PATH, "w");

    if (backup == NULL) {
        printf("Warning: Backup file could not be created.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(backup, "%d|%s|%.2f\n",
                students[i].rollNumber,
                students[i].name,
                students[i].marks);
    }

    fclose(backup);
}

/**
 * File se purana student data load karta hai program start hote hi.
 * @param students Student array jisme data load hoga
 * @return Load kiye gaye students ki sankhya
 */
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

/**
 * Student data ko CSV format mein export karta hai (Excel ke liye).
 * @param students Student array
 * @param count Total students ki sankhya
 */
void exportToCSV(struct Student students[], int count) {
    FILE *file = fopen(CSV_PATH, "w");

    if (file == NULL) {
        printf("Error: Could not create CSV file!\n");
        return;
    }

    // Header row
    fprintf(file, "Roll Number,Name,Marks,Grade\n");

    for (int i = 0; i < count; i++) {
        char grade = getGrade(students[i].marks);
        fprintf(file, "%d,%s,%.2f,%c\n",
                students[i].rollNumber,
                students[i].name,
                students[i].marks,
                grade);
    }

    fclose(file);
    printf("Data exported to students.csv successfully!\n");
}