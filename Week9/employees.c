#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

/* Module storage */
static int    empID[MAX_EMPLOYEES];
static char   empName[MAX_EMPLOYEES][EMP_NAME_LEN];
static char   empDept[MAX_EMPLOYEES][EMP_DEPT_LEN];
static double empBasic[MAX_EMPLOYEES];
static int    empCount = 0;

/* ============================================================
 *  Core employee operations
 * ============================================================ */
void addEmployee(void)
{
    if (empCount >= MAX_EMPLOYEES) {
        printf("\n  [!] Employee storage is full.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    int newID = readInt("Employee ID : ");

    for (int i = 0; i < empCount; i++) {
        if (empID[i] == newID) {
            printf("  [!] An employee with that ID already exists.\n");
            return;
        }
    }

    empID[empCount] = newID;

    readLine("Name        : ", empName[empCount], EMP_NAME_LEN);
    if (strlen(empName[empCount]) == 0) {
        printf("  [!] Name cannot be empty.\n");
        return;
    }

    readLine("Department  : ", empDept[empCount], EMP_DEPT_LEN);

    empBasic[empCount] = readDouble("Basic Salary: ");

    empCount++;
    printf("\n  Employee added. Total employees: %d\n", empCount);
}

void listEmployees(void)
{
    if (empCount == 0) {
        printf("\n  No employees added yet.\n");
        return;
    }

    printf("\n--------------------------------------------------\n");
    printf("%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Basic");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < empCount; i++) {
        printf("%-6d %-20s %-15s %12.2f\n",
               empID[i], empName[i], empDept[i], empBasic[i]);
    }

    printf("--------------------------------------------------\n");
    printf("  Total: %d\n", empCount);
}

void searchEmployee(void)
{
    if (empCount == 0) {
        printf("\n  No employees added yet.\n");
        return;
    }

    int target = readInt("\nEnter Employee ID: ");

    for (int i = 0; i < empCount; i++) {
        if (empID[i] == target) {
            printf("\n  Found:\n");
            printf("  ID        : %d\n",   empID[i]);
            printf("  Name      : %s\n",   empName[i]);
            printf("  Department: %s\n",   empDept[i]);
            printf("  Basic     : %.2f\n", empBasic[i]);
            return;
        }
    }

    printf("  [!] No employee found with ID %d.\n", target);
}

/* ============================================================
 *  TEXT FILE  -  save / load
 *  Format: ID|Name|Department|Basic
 * ============================================================ */
int saveEmployeesText(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("saveEmployeesText");
        return 0;
    }

    for (int i = 0; i < empCount; i++) {
        fprintf(fp, "%d|%s|%s|%.2f\n",
                empID[i], empName[i], empDept[i], empBasic[i]);
    }

    fclose(fp);
    printf("\n  Saved %d employee(s) to %s\n", empCount, filename);
    return empCount;
}

int loadEmployeesText(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("loadEmployeesText");
        return -1;
    }

    empCount = 0;
    int id;
    char name[EMP_NAME_LEN];
    char dept[EMP_DEPT_LEN];
    double basic;

    while (fscanf(fp, "%d|%49[^|]|%29[^|]|%lf\n",
                  &id, name, dept, &basic) == 4) {

        if (empCount >= MAX_EMPLOYEES) break;

        empID[empCount]      = id;
        strcpy(empName[empCount], name);
        strcpy(empDept[empCount], dept);
        empBasic[empCount]   = basic;
        empCount++;
    }

    fclose(fp);
    printf("\n  Loaded %d employee(s) from %s\n", empCount, filename);
    return empCount;
}

/* ============================================================
 *  BINARY FILE  -  save / load
 *  Format: id | name | department | basic (raw bytes)
 * ============================================================ */
int saveEmployeesBinary(const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("saveEmployeesBinary");
        return 0;
    }

    for (int i = 0; i < empCount; i++) {
        fwrite(&empID[i],      sizeof(empID[i]),      1, fp);
        fwrite(empName[i],     sizeof(char),          EMP_NAME_LEN, fp);
        fwrite(empDept[i],     sizeof(char),          EMP_DEPT_LEN, fp);
        fwrite(&empBasic[i],   sizeof(empBasic[i]),   1, fp);
    }

    fclose(fp);
    printf("\n  Saved %d employee(s) to %s (binary)\n", empCount, filename);
    return empCount;
}

int loadEmployeesBinary(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("loadEmployeesBinary");
        return -1;
    }

    empCount = 0;

    while (empCount < MAX_EMPLOYEES) {
        int    id;
        char   name[EMP_NAME_LEN] = {0};
        char   dept[EMP_DEPT_LEN] = {0};
        double basic;

        if (fread(&id,  sizeof(id),  1, fp) != 1) break;
        if (fread(name, sizeof(char), EMP_NAME_LEN, fp) != EMP_NAME_LEN) break;
        if (fread(dept, sizeof(char), EMP_DEPT_LEN, fp) != EMP_DEPT_LEN) break;
        if (fread(&basic, sizeof(basic), 1, fp) != 1) break;

        empID[empCount]    = id;
        strcpy(empName[empCount], name);
        strcpy(empDept[empCount], dept);
        empBasic[empCount] = basic;
        empCount++;
    }

    fclose(fp);
    printf("\n  Loaded %d employee(s) from %s (binary)\n", empCount, filename);
    return empCount;
}