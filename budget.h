#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

/* Budget Management module.
   Data is kept in parallel arrays: record i is the tuple
   (departments[i], allocated[i], expenditure[i]). */

#define MAX_BUDGETS 100

/* Adds a departmental budget. Duplicate department names are rejected.
   Expenditure starts at zero. Returns the new count (unchanged if full). */
int addBudget(char departments[][TEXT_LEN], double allocated[],
              double expenditure[], int count);

/* Adds an amount to the expenditure of one department, chosen by name.
   Returns 1 when the department exists, 0 otherwise. */
int addExpenditure(const char departments[][TEXT_LEN], double expenditure[],
                   int count);

/* Displays every budget in the format used in the project brief:
   department, allocated, expenditure, remaining, WITHIN/OVER BUDGET status. */
void displayBudgets(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count);

/* Lists every department whose expenditure is greater than its allocation.
   Expenditure exactly equal to the allocation counts as WITHIN budget. */
void listOverBudget(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count);

/* Sub menu loop: add budget, add expenditure, display, over budget list, back. */
void budgetMenu(char departments[][TEXT_LEN], double allocated[],
                double expenditure[], int *count);

#endif
