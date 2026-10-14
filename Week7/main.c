#include <stdio.h>
#include <string.h>

#define NAME_LEN  100
#define TOWN_LEN  50
#define EMAIL_LEN 100
#define PHONE_LEN 30

int main(void)
{
    /* -------- Character arrays (strings) -------- */
    char supplierName[NAME_LEN];
    char email[EMAIL_LEN];
    char phone[PHONE_LEN];
    char town[TOWN_LEN];

    char copyOfName[NAME_LEN];
    char description[NAME_LEN + TOWN_LEN + 40];

    char searchName[NAME_LEN];

    /* -------- Title -------- */
    printf("==================================================\n");
    printf("       MUNICIPAL SUPPLIER MANAGEMENT\n");
    printf("             Week 7 - Strings\n");
    printf("==================================================\n\n");

    /* -------- Capture supplier information -------- */
    printf("Enter supplier name : ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter email         : ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone         : ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town          : ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    /* -------- Display the record -------- */
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("  Name  : %s\n", supplierName);
    printf("  Email : %s\n", email);
    printf("  Phone : %s\n", phone);
    printf("  Town  : %s\n", town);

    /* -------- String lengths (strlen) -------- */
    printf("\n--- STRING LENGTHS ---\n");
    printf("  Name  length : %zu\n", strlen(supplierName));
    printf("  Email length : %zu\n", strlen(email));
    printf("  Town  length : %zu\n", strlen(town));

    /* -------- Copy the name (strcpy) -------- */
    strcpy(copyOfName, supplierName);
    printf("\n--- COPY TEST ---\n");
    printf("  Original : %s\n", supplierName);
    printf("  Copy     : %s\n", copyOfName);

    /* -------- Build a sentence (strcat) -------- */
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("\n--- DESCRIPTION ---\n");
    printf("  %s\n", description);

    /* -------- Search (strcmp) -------- */
    printf("\nEnter supplier name to search for: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0) {
        printf("  Supplier found.\n");
    } else {
        printf("  Supplier not found.\n");
    }

    return 0;
}