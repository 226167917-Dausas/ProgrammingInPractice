#include <stdio.h>

#define NUM_EMPLOYEES 50

int main(void)
{
    double salary;
    double total   = 0.0;
    double highest = 0.0;
    double lowest  = 0.0;
    double average;

    printf("==================================================\n");
    printf("       MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("==================================================\n\n");
    printf("You will be asked to enter %d salaries.\n\n", NUM_EMPLOYEES);

    for (int i = 1; i <= NUM_EMPLOYEES; i++) {

        printf("Enter salary for employee %2d: ", i);
        scanf("%lf", &salary);

        total = total + salary;

        if (i == 1) {
            highest = salary;
            lowest  = salary;
        }

        if (salary > highest) {
            highest = salary;
        }

        if (salary < lowest) {
            lowest = salary;
        }
    }

    average = total / NUM_EMPLOYEES;

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("               SALARY REPORT\n");
    printf("--------------------------------------------------\n");
    printf("  %-20s : %12.2f\n", "Employees",      NUM_EMPLOYEES);
    printf("  %-20s : %12.2f\n", "Total Salaries", total);
    printf("  %-20s : %12.2f\n", "Average Salary", average);
    printf("  %-20s : %12.2f\n", "Highest Salary", highest);
    printf("  %-20s : %12.2f\n", "Lowest Salary",  lowest);
    printf("--------------------------------------------------\n");

    return 0;
}