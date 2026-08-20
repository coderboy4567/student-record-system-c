#include <stdio.h>
#include "../include/student.h"

int main(void) {
    int choice;
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    studentCount = loadFromFile(students);
    printf("Loaded %d student(s) from file.\n", studentCount);

    do {
        displayMenu();
        choice = getValidInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3: {
                int roll = getValidInt("Enter Roll Number to search: ");
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
            case 7: {
                printf("Sort by: 1. Marks  2. Name  3. Roll Number\n");
                int sortChoice = getValidInt("Enter choice: ");
                if (sortChoice == 1) {
                sortStudents(students, studentCount);
                printf("Sorted by marks (descending).\n");
                } else if (sortChoice == 2) {
                sortByName(students, studentCount);
                printf("Sorted by name (A-Z).\n");
                } else if (sortChoice == 3) {
                sortByRoll(students, studentCount);
                printf("Sorted by roll number (ascending).\n");
                } else {
                printf("Invalid sort choice!\n");
                }
                break;
            }
            case 8:
                showStatistics(students, studentCount);
                break;
            case 9: {
                char name[50];
                printf("Enter Name to search: ");
                scanf(" %[^\n]", name);
                int index = searchStudentByName(students, studentCount, name);
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
   printf("7. Sort Students\n");
    printf("8. Show Statistics\n");
    printf("9. Search Student by Name\n");
}