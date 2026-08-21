#include <stdio.h>
#include "../include/student.h"

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