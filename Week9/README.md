# Week 9 Lab - Multi-File MFMS (Simple Version)

## Files

| File | Purpose |
|------|---------|
| `main.c` | Menu, coordinates the program |
| `employees.c` / `employees.h` | Employee data storage and operations |
| `utilities.c` / `utilities.h` | Reusable input helpers |
| `README.md` | This file |

## Build (separate compilation + linking)

    gcc -std=c99 -Wall -Wextra -pedantic -c main.c
    gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
    gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
    gcc main.o employees.o utilities.o -o mfms

## Run

Windows:  mfms.exe
Linux/macOS:  ./mfms