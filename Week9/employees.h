#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50
#define EMP_NAME_LEN  50
#define EMP_DEPT_LEN  30

/* ---- Core employee operations ---- */
void addEmployee(void);
void listEmployees(void);
void searchEmployee(void);

/* ---- File handling (Week 10) ---- */
int  saveEmployeesText(const char *filename);
int  loadEmployeesText(const char *filename);
int  saveEmployeesBinary(const char *filename);
int  loadEmployeesBinary(const char *filename);

#endif