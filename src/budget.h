#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"


#define MAX_BUDGETS 100

//declaration of functions
int addBudget(char departments[][TEXT_LEN], double allocated[],
              double expenditure[], int count);


int addExpenditure(const char departments[][TEXT_LEN], double expenditure[],
                   int count);


void displayBudgets(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count);


void listOverBudget(const char departments[][TEXT_LEN], const double allocated[],
                    const double expenditure[], int count);


void budgetMenu(char departments[][TEXT_LEN], double allocated[],
                double expenditure[], int *count);

#endif
