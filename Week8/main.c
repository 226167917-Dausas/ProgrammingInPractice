#include <stdio.h>

/* -------- Function prototypes -------- */
void  displayWelcome(void);
void  displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int   searchEmployee(int id, int ids[], int size);

/* ============================================================
 *  MAIN - just calls each function to demonstrate it
 * ============================================================ */
int main(void)
{
    int ids[] = {101, 102, 103, 104, 105};

    displayWelcome();
    displayMenu();

    printf("\nVAT on 1000          : %.2f\n", calculateVAT(1000));
    printf("Salary (15k+3k+2k)   : %.2f\n", calculateSalary(15000, 3000, 2000));
    printf("Budget (1500k-1250k) : %.2f\n", calculateBudget(1500000, 1250000));

    int pos = searchEmployee(103, ids, 5);
    if (pos >= 0) printf("Employee 103 found at position %d\n", pos);
    else          printf("Employee 103 not found\n");

    return 0;
}

/* ============================================================
 *  Function definitions
 * ============================================================ */
void displayWelcome(void)
{
    printf("==================================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("            Week 8 - Functions\n");
    printf("==================================================\n");
}

void displayMenu(void)
{
    printf("\n--- MAIN MENU (example) ---\n");
    printf("  1. Calculate VAT\n");
    printf("  2. Calculate Salary\n");
    printf("  3. Calculate Budget\n");
    printf("  4. Search Employee\n");
    printf("  5. Exit\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
        if (ids[i] == id)
            return i;
    return -1;
}