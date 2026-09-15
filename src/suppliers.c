#include <stdio.h>
#include <string.h>
#include "common.h"
#include "suppliers.h"

int addSupplier(int ids[], char names[][TEXT_LEN], char emails[][TEXT_LEN],
                char phones[][TEXT_LEN], char towns[][TEXT_LEN], int count)
{
    if (count >= MAX_SUPPLIERS) {
        printf("The supplier register is full (maximum %d suppliers).\n",
               MAX_SUPPLIERS);
        return count;
    }

    printf("--- Add Supplier ---\n");

    /* Supplier IDs are assigned in registration order, starting from 1. */
    ids[count] = count + 1;

    readText("Supplier name: ", names[count], TEXT_LEN);
    readText("Email: ", emails[count], TEXT_LEN);
    readText("Telephone number: ", phones[count], TEXT_LEN);
    readText("Town/Location: ", towns[count], TEXT_LEN);

    printf("Supplier %d added.\n", ids[count]);
    return count + 1;
}

void printSupplier(int id, const char name[], const char email[],
                   const char phone[], const char town[])
{
    printf("%-6d %-24s %-28s %-14s %-15s\n", id, name, email, phone, town);
}

void displaySuppliers(int ids[], const char names[][TEXT_LEN],
                      const char emails[][TEXT_LEN], const char phones[][TEXT_LEN],
                      const char towns[][TEXT_LEN], int count)
{
    int i;

    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("--- Supplier Register ---\n");
    printf("%-6s %-24s %-28s %-14s %-15s %7s\n",
           "ID", "Name", "Email", "Phone", "Town", "Length");
    for (i = 0; i < count; i++) {
        printSupplier(ids[i], names[i], emails[i], phones[i], towns[i]);
    }
}

void showNameLengths(const char names[][TEXT_LEN], int count)
{
    int i;

    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("%s: %d characters\n", names[i], (int)strlen(names[i]));
    }
}

int searchSupplier(const char names[][TEXT_LEN], int count, const char target[])
{
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(names[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

void supplierMenu(int ids[], char names[][TEXT_LEN], char emails[][TEXT_LEN],
                  char phones[][TEXT_LEN], char towns[][TEXT_LEN], int *count)
{
    int choice;
    int index;
    char target[TEXT_LEN];

    for (;;) {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Show supplier name lengths\n");
        printf("0. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 0, 4);

        if (choice == 0) {
            return;
        }

        switch (choice) {
        case 1:
            *count = addSupplier(ids, names, emails, phones, towns, *count);
            break;
        case 2:
            displaySuppliers(ids, names, emails, phones, towns, *count);
            break;
        case 3:
            if (*count == 0) {
                printf("No suppliers registered yet.\n");
                break;
            }
            readText("Supplier name to search: ", target, TEXT_LEN);
            index = searchSupplier(names, *count, target);
            if (index >= 0) {
                printSupplier(ids[index], names[index], emails[index],
                              phones[index], towns[index]);
            } else {
                printf("No supplier named %s was found.\n", target);
            }
            break;
        case 4:
            showNameLengths(names, *count);
            break;
        default:
            break;
        }
    }
}
