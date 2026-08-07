#include <stdio.h>
#include "../include/student.h"

void displayMenu(void);

int main(void) {
    int choice;

    // Test: ek sample student struct bana rahe hain check karne ke liye
    struct Student testStudent = {1, "Adnan", 85.5};
    printf("Test Student -> Roll: %d, Name: %s, Marks: %.2f\n\n",
           testStudent.rollNumber, testStudent.name, testStudent.marks);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Add Student - coming soon\n");
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
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
}