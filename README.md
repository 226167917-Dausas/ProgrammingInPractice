# PAP521S — Programming in Practice

Weekly lab work for **PAP521S Programming in Practice**, Semester 2 2026.
**Student:** 226167917 — Dausas
**Language:** C (C99)
**Compiler:** GCC 15.2.0 (MSYS2 UCRT64)
**Editor:** Visual Studio Code

## Weekly Labs

| Week | Topic | Program |
|------|-------|---------|
| 1 | Introduction to C | Municipal Financial Management System (data capture) |
| 2 | Variables & Data Types | Municipal Budget Calculator |
| 3 | Operators & Expressions | Employee Salary Calculator |
| 4 | Decision Making | Tender Evaluation |
| 5 | Loops | Municipal Employee Salary Analysis |
| 6 | Arrays | Municipal Information Management System |
| 7 | Strings | Supplier Management |
| 8 | Functions | Reusable MFMS Functions |
| 9 | Multi-File Programming | Modular MFMS (main + employees + utilities) |
| 10 | File Handling | Persistent MFMS (text + binary save/load) |

## Repository Structure

    ProgrammingInPractice/
    ├── .gitignore
    ├── README.md
    ├── Week1/    main.c
    ├── Week2/    main.c
    ├── Week3/    main.c
    ├── Week4/    main.c
    ├── Week5/    Salary_analysis.c
    ├── Week6/    main.c
    ├── Week7/    main.c
    ├── Week8/    main.c
    └── Week9/    main.c, employees.c/h, utilities.c/h, README.md

## How to Compile & Run

Every week follows the same pattern:

    cd Week1
    gcc main.c -o municipal
    ./municipal.exe          (Windows)

For **Week 9** (multi-file), use separate compilation:

    cd Week9
    gcc -std=c99 -Wall -Wextra -pedantic -c main.c
    gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
    gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
    gcc main.o employees.o utilities.o -o mfms
    ./mfms.exe

For **Week 10**, run the Week 9 build then use menu options 4/5 (text) or 6/7 (binary) to save/load employee records.

## Author

- **Name:** Dausas
- **Student number:** 226167917
- **Module:** PAP521S — Programming in Practice
- **Institution:** Namibia University of Science and Technology (NUST)