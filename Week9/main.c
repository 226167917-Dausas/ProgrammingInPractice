#include <stdio.h>
#include "employees.h"
#include "utilities.h"

#define TEXT_FILE   "employees.txt"
#define BINARY_FILE "employees.dat"

static void displayMenu(void);

int main(void)
{
    int choice;

    printf("==================================================\n");
    printf("      MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("           Week 10 - File Handling\n");
    printf("==================================================\n");

    do {
        displayMenu();
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addEmployee();    pauseScreen(); break;
            case 2: listEmployees();  pauseScreen(); break;
            case 3: searchEmployee(); pauseScreen(); break;
            case 4: saveEmployeesText(TEXT_FILE);   pauseScreen(); break;
            case 5: loadEmployeesText(TEXT_FILE);   pauseScreen(); break;
            case 6: saveEmployeesBinary(BINARY_FILE); pauseScreen(); break;
            case 7: loadEmployeesBinary(BINARY_FILE); pauseScreen(); break;
            case 8: printf("\nGoodbye.\n"); break;
            default:
                printf("\n  [!] Invalid choice. Please select 1-8.\n");
        }
    } while (choice != 8);

    return 0;
}

static void displayMenu(void)
{
    printf("\n==================================================\n");
    printf("                   MAIN MENU\n");
    printf("==================================================\n");
    printf("  1. Add Employee\n");
    printf("  2. List Employees\n");
    printf("  3. Search Employee\n");
    printf("  4. Save (text)\n");
    printf("  5. Load (text)\n");
    printf("  6. Save (binary)\n");
    printf("  7. Load (binary)\n");
    printf("  8. Exit\n");
    printf("==================================================\n");
}