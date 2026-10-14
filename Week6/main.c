#include <stdio.h>

#define NUM_EMPLOYEES 5

int main(void)
{
    /* -------- The array -------- */
    double salaries[NUM_EMPLOYEES];

    double total   = 0.0;
    double average;
    double highest;
    double lowest;
    double searchValue;
    int    found;

    /* -------- Title -------- */
    printf("==================================================\n");
    printf("     MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("             Week 6 - Arrays\n");
    printf("==================================================\n\n");

    /* -------- Capture salaries into the array -------- */
    printf("Enter %d employee salaries:\n\n", NUM_EMPLOYEES);

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Employee %2d salary: ", i + 1);
        scanf("%lf", &salaries[i]);
    }

    /* -------- Initialise highest / lowest from first element -------- */
    highest = salaries[0];
    lowest  = salaries[0];

    /* -------- Loop once for total, highest, lowest -------- */
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        total += salaries[i];
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest  = salaries[i];
    }

    average = total / NUM_EMPLOYEES;

    /* -------- Display all salaries -------- */
    printf("\n--- All Salaries ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("  Employee %2d : %12.2f\n", i + 1, salaries[i]);
    }

    /* -------- Report -------- */
    printf("\n--------------------------------------------------\n");
    printf("              SALARY REPORT\n");
    printf("--------------------------------------------------\n");
    printf("  Employees  : %d\n",    NUM_EMPLOYEES);
    printf("  Total      : %.2f\n",  total);
    printf("  Average    : %.2f\n",  average);
    printf("  Highest    : %.2f\n",  highest);
    printf("  Lowest     : %.2f\n",  lowest);
    printf("--------------------------------------------------\n");

    /* -------- Search -------- */
    printf("\nEnter a salary to search for: ");
    scanf("%lf", &searchValue);

    found = 0;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        if (salaries[i] == searchValue) {
            printf("  Found at position %d (Employee %d).\n", i, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("  Salary %.2f not found.\n", searchValue);
    }

    return 0;
}