
#include <stdio.h>

int main(void)
{
    double revenue  = 0.0;
    double expenses = 0.0;
    double balance;

    /* -------- Title banner -------- */
    printf("==================================================\n");
    printf("        MUNICIPAL BUDGET CALCULATOR\n");
    printf("             Week 2 - Budget Analysis\n");
    printf("==================================================\n\n");

    /* -------- Capture user input -------- */
    printf("Enter total revenue  : ");
    scanf("%lf", &revenue);

    printf("Enter total expenses : ");
    scanf("%lf", &expenses);

    /* -------- Calculate balance -------- */
    balance = revenue - expenses;

    /* -------- Display report -------- */
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("                BUDGET SUMMARY\n");
    printf("--------------------------------------------------\n");
    printf("  %-15s : %.2f\n", "Revenue",  revenue);
    printf("  %-15s : %.2f\n", "Expenses", expenses);
    printf("  %-15s : %.2f\n", "Balance",  balance);
    printf("--------------------------------------------------\n");

    if (balance > 0.0) {
        printf("  Status          : SURPLUS of %.2f\n", balance);
    }
    else if (balance < 0.0) {
        printf("  Status          : DEFICIT of %.2f\n", -balance);
    }
    else {
        printf("  Status          : BALANCED\n");
    }

    printf("--------------------------------------------------\n");
    printf("  Report generated successfully. Thank you.\n");
    printf("--------------------------------------------------\n\n");

    return 0;
}