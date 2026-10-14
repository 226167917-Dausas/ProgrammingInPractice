#include <stdio.h>
#include <string.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    char buffer[100];
    int  value;

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;
        if (sscanf(buffer, "%d", &value) == 1) return value;

        printf("  [!] Invalid input. Please enter a whole number.\n");
    }
}

double readDouble(const char *prompt)
{
    char   buffer[100];
    double value;

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0.0;
        if (sscanf(buffer, "%lf", &value) == 1 && value >= 0.0) return value;

        printf("  [!] Invalid input. Please enter a non-negative number.\n");
    }
}

void readLine(const char *prompt, char *dest, int size)
{
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(dest, size, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }
    }
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    fflush(stdout);
    getchar();
}