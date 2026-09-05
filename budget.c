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
