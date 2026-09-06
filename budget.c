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
