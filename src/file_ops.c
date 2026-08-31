#include <stdio.h>
#include "../include/student.h"

/*
 * Write all student records to an opened file.
 * This avoids repeating the same file-writing code.
 */
static void writeStudentData(
    FILE *file,
    struct Student students[],
    int count
)
{
    for (int i = 0; i < count; i++) {
        fprintf(file,
                "%d|%s|%.2f\n",
                students[i].rollNumber,
                students[i].name,
                students[i].marks);
    }
}

/* Save student data to the main file and create a backup. */
void saveToFile(struct Student students[], int count)
{
    /* Open the main data file for writing. */
    FILE *file = fopen(FILE_PATH, "w");

    if (file == NULL) {
        printf("Error: Could not open file to save data!\n");
        return;
    }

    writeStudentData(file, students, count);
    fclose(file);

    /* Create a backup copy of the student data. */
    FILE *backup = fopen(BACKUP_PATH, "w");

    if (backup == NULL) {
        printf("Warning: Backup file could not be created.\n");
        return;
    }

    writeStudentData(backup, students, count);
    fclose(backup);
}

/* Load previously saved student data from the file. */
int loadFromFile(struct Student students[])
{
    FILE *file = fopen(FILE_PATH, "r");

    /* Start with an empty list if the file does not exist. */
    if (file == NULL) {
        return 0;
    }

    int count = 0;

    /*
     * Read student records until the file ends
     * or the maximum limit is reached.
     */
    while (count < MAX_STUDENTS &&
           fscanf(file,
                  "%d|%49[^|]|%f",
                  &students[count].rollNumber,
                  students[count].name,
                  &students[count].marks) == 3) {

        count++;
    }

    fclose(file);

    return count;
}

/* Export student data to a CSV file. */
void exportToCSV(struct Student students[], int count)
{
    FILE *file = fopen(CSV_PATH, "w");

    if (file == NULL) {
        printf("Error: Could not create CSV file!\n");
        return;
    }

    /* Write the CSV column names first. */
    fprintf(file, "Roll Number,Name,Marks,Grade\n");

    /* Write each student's data as a CSV row. */
    for (int i = 0; i < count; i++) {
        fprintf(file,
                "%d,%s,%.2f,%c\n",
                students[i].rollNumber,
                students[i].name,
                students[i].marks,
                getGrade(students[i].marks));
    }

    fclose(file);

    printf("Data exported to students.csv successfully!\n");
}