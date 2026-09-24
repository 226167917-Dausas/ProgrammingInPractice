#include <stdio.h>

int main(void)
{
    char  supplierName[50];
    double price;
    double budget;
    int   registered;
    int   documentsComplete;

    printf("==================================================\n");
    printf("            TENDER EVALUATION SYSTEM\n");
    printf("==================================================\n\n");

    printf("Enter supplier name                 : ");
    scanf("%49s", supplierName);

    printf("Enter tender price                  : ");
    scanf("%lf", &price);

    printf("Enter available budget              : ");
    scanf("%lf", &budget);

    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);

    printf("Are documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("              TENDER RESULT\n");
    printf("--------------------------------------------------\n");
    printf("  %-20s : %s\n", "Supplier", supplierName);
    printf("  %-20s : %.2f\n", "Tender Price", price);
    printf("  %-20s : %.2f\n", "Available Budget", budget);
    printf("--------------------------------------------------\n");

    if (registered == 0 || documentsComplete == 0) {
        printf("  Status               : DISQUALIFIED\n");
        printf("  Reason               : Registration or documents missing\n");
    }
    else if (price > budget) {
        printf("  Status               : DISQUALIFIED\n");
        printf("  Reason               : Price exceeds budget\n");
    }
    else {
        printf("  Status               : QUALIFIED\n");
        printf("  Reason               : All requirements met\n");
    }

    printf("--------------------------------------------------\n");

    return 0;
}