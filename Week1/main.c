
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Configuration constants ---------- */
#define NAME_LEN     50
#define LINE_LEN     100
#define LABEL_WIDTH  15

/* ---------- Function prototypes ---------- */
static void print_title(void);
static void print_footer(void);
static void trim_newline(char *s);
static int  read_line(const char *prompt, char *dest, size_t size);
static int  read_int(const char *prompt, int *dest);
static void print_report(const char *municipality,
                         const char *mayor,
                         int         population);

/* ============================================================
 *  main() - program entry point
 * ============================================================ */
int main(void)
{
    char municipality[NAME_LEN];
    char mayor[NAME_LEN];
    int  population = 0;

    /* -------- Title banner -------- */
    print_title();

    /* -------- Capture user input -------- */
    if (!read_line("Enter Municipality Name : ", municipality, sizeof(municipality))) {
        printf("\nNo input received. Exiting.\n");
        return 1;
    }

    if (!read_line("Enter Mayor's Name      : ", mayor, sizeof(mayor))) {
        printf("\nNo input received. Exiting.\n");
        return 1;
    }

    if (!read_int("Enter Population        : ", &population)) {
        printf("\nNo input received. Exiting.\n");
        return 1;
    }

    /* -------- Display the report -------- */
    print_report(municipality, mayor, population);

    /* -------- Farewell -------- */
    print_footer();

    return 0;
}

/* ============================================================
 *  print_title()
 *      Draws the top banner for the program.
 * ============================================================ */
static void print_title(void)
{
    printf("==================================================\n");
    printf("      MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("           Week 1 - Municipality Data Capture\n");
    printf("==================================================\n\n");
}

/* ============================================================
 *  print_footer()
 *      Draws the closing banner.
 * ============================================================ */
static void print_footer(void)
{

    printf("  Report generated successfully. Thank you.\n");
    printf("--------------------------------------------------\n\n");
}

/* ============================================================
 *  trim_newline()
 *      Removes the trailing newline character left by fgets().
 * ============================================================ */
static void trim_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

/* ============================================================
 *  read_line()
 *      Prompts the user and reads an entire line of text safely.
 *      Handles lines longer than the destination buffer by
 *      discarding the extra characters.
 *
 *      Returns 1 on success, 0 on end-of-input / error.
 * ============================================================ */
static int read_line(const char *prompt, char *dest, size_t size)
{
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(dest, (int)size, stdin) == NULL) {
        return 0;   /* EOF or read error */
    }

    /* If no newline was found, the line was too long for the buffer.
     * Flush the remaining characters so they don't leak into the
     * next input prompt. */
    if (strchr(dest, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            /* discard */
        }
    }

    trim_newline(dest);
    return 1;
}

/* ============================================================
 *  read_int()
 *      Prompts the user for a whole number and validates the
 *      input using strtol(). Loops until a valid non-negative
 *      integer is entered.
 *
 *      Returns 1 on success, 0 on end-of-input / error.
 * ============================================================ */
static int read_int(const char *prompt, int *dest)
{
    char  buffer[LINE_LEN];
    char *endptr;
    long  value;

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 0;   /* EOF */
        }

        value = strtol(buffer, &endptr, 10);

        /* Case 1: no digits at all */
        if (endptr == buffer) {
            printf("  [!] Invalid input. Please enter a whole number.\n");
            continue;
        }

        /* Case 2: extra non-numeric characters remain */
        if (*endptr != '\n' && *endptr != '\0') {
            printf("  [!] Invalid input. Please enter only digits.\n");
            continue;
        }

        /* Case 3: negative value */
        if (value < 0) {
            printf("  [!] Population cannot be negative.\n");
            continue;
        }

        /* Case 4: too large for int */
        if (value > 2147483647L) {
            printf("  [!] Population is too large.\n");
            continue;
        }

        *dest = (int)value;
        return 1;
    }
}

/* ============================================================
 *  print_report()
 *      Prints the final formatted municipal report.
 * ============================================================ */
static void print_report(const char *municipality,
                         const char *mayor,
                         int         population)
{
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("                 MUNICIPAL REPORT\n");
    printf("--------------------------------------------------\n");
    printf("  %-*s : %s\n", LABEL_WIDTH, "Municipality", municipality);
    printf("  %-*s : %s\n", LABEL_WIDTH, "Mayor",        mayor);
    printf("  %-*s : %d\n", LABEL_WIDTH, "Population",   population);
    printf("--------------------------------------------------\n");

    return 0;
}