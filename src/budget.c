#include <stdio.h>
#include <string.h>
#include "common.h"
#include "budget.h"

int addBudget(char departments[][TEXT_LEN], double allocated[],
              double expenditure[], int count)
{
    int i;

    if (count >= MAX_BUDGETS) {
        printf("The budget register is full (maximum %d departments).\n",
               MAX_BUDGETS);
        return count;
    }

    printf("--- Add Departmental Budget ---\n");
    readText("Department: ", departments[count], TEXT_LEN);

    /* Each department may appear only once. */
    for (i = 0; i < count; i++) {
        if (strcmp(departments[i], departments[count]) == 0) {
            printf("Department %s already has a budget.\n", departments[count]);
            return count;
        }
    }

    allocated[count]    = readDoublePositive("Allocated budget (N$): ");
    expenditure[count]  = 0.0;
    printf("Budget for %s registered.\n", departments[count]);
    return count + 1;
}

int addExpenditure(const char departments[][TEXT_LEN], double expenditure[],
                   int count)
{
    char target[TEXT_LEN];
    int i;
    double amount;

    if (count == 0) {
        printf("No budgets registered yet.\n");
        return 0;
    }

    readText("Department name: ", target, TEXT_LEN);

    for (i = 0; i < count; i++) {
        if (strcmp(departments[i], target) == 0) {
            amount = readDoublePositive("Expenditure amount (N$): ");
            expenditure[i] += amount;
            printf("Expenditure for %s updated.\n", departments[i]);
            return 1;
        }
    }
    printf("No department named %s was found.\n", target);
    return 0;
}

void displayBudgets(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count)
{
    int i;

    if (count == 0) {
        printf("No budgets registered yet.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nDepartment: %s\n", departments[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", expenditure[i]);
        printf("Remaining Budget: N$%.2f\n", allocated[i] - expenditure[i]);
        if (expenditure[i] <= allocated[i]) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: OVER BUDGET\n");
        }
    }
}

void listOverBudget(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count)
{
    int i;
    int overCount = 0;

    if (count == 0) {
        printf("No budgets registered yet.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        if (expenditure[i] > allocated[i]) {
            printf("%s: spent N$%.2f of N$%.2f\n", departments[i],
                   expenditure[i], allocated[i]);
            overCount++;
        }
    }
    if (overCount == 0) {
        printf("No department has exceeded its budget.\n");
    }
}

void budgetMenu(char departments[][TEXT_LEN], double allocated[],
                double expenditure[], int *count)
{
    int choice;

    for (;;) {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add departmental budget\n");
        printf("2. Add expenditure\n");
        printf("3. Display budgets\n");
        printf("4. Over budget departments\n");
        printf("0. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 0, 4);

        if (choice == 0) {
            return;
        }

        switch (choice) {
        case 1:
            *count = addBudget(departments, allocated, expenditure, *count);
            break;
        case 2:
            addExpenditure(departments, expenditure, *count);
            break;
        case 3:
            displayBudgets(departments, allocated, expenditure, *count);
            break;
        case 4:
            listOverBudget(departments, allocated, expenditure, *count);
            break;
        default:
            break;
        }
    }
}
