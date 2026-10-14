#include <stdio.h>

int main(void)
{
    double basicSalary, housing, transport, tax;
    double grossSalary, netSalary;

    printf("==================================================\n");
    printf("         EMPLOYEE SALARY CALCULATOR\n");
    printf("==================================================\n\n");

    printf("Enter basic salary       : ");
    scanf("%lf", &basicSalary);

    printf("Enter housing allowance  : ");
    scanf("%lf", &housing);

    printf("Enter transport allowance: ");
    scanf("%lf", &transport);

    printf("Enter tax                : ");
    scanf("%lf", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary   = grossSalary - tax;

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("              SALARY REPORT\n");
    printf("--------------------------------------------------\n");
    printf("  %-20s : %10.2f\n", "Basic Salary",  basicSalary);
    printf("  %-20s : %10.2f\n", "Housing",       housing);
    printf("  %-20s : %10.2f\n", "Transport",     transport);
    printf("  %-20s : %10.2f\n", "Gross Salary",  grossSalary);
    printf("  %-20s : %10.2f\n", "Tax",           tax);
    printf("  %-20s : %10.2f\n", "Net Salary",    netSalary);
    printf("--------------------------------------------------\n");

    return 0;
}