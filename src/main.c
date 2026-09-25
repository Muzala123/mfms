#include <stdio.h>
#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

/* Main menu of the Municipal Financial Management System.
   All module data lives here in parallel arrays and is passed to the
   module sub menus. Data is kept in memory only and is lost on exit. */

int main(void)
{
    int empIds[MAX_EMPLOYEES];
    char empNames[MAX_EMPLOYEES][TEXT_LEN];
    char empDepts[MAX_EMPLOYEES][TEXT_LEN];
    double empBasic[MAX_EMPLOYEES];
    double empHousing[MAX_EMPLOYEES];
    double empTransport[MAX_EMPLOYEES];
    int empCount = 0;

    char budDepts[MAX_BUDGETS][TEXT_LEN];
    double budAllocated[MAX_BUDGETS];
    double budExpenditure[MAX_BUDGETS];
    int budCount = 0;

    int supIds[MAX_SUPPLIERS];
    char supNames[MAX_SUPPLIERS][TEXT_LEN];
    char supEmails[MAX_SUPPLIERS][TEXT_LEN];
    char supPhones[MAX_SUPPLIERS][TEXT_LEN];
    char supTowns[MAX_SUPPLIERS][TEXT_LEN];
    int supCount = 0;

    int astIds[MAX_ASSETS];
    char astNames[MAX_ASSETS][TEXT_LEN];
    char astTypes[MAX_ASSETS][TEXT_LEN];
    double astValues[MAX_ASSETS];
    char astDepts[MAX_ASSETS][TEXT_LEN];
    char astConditions[MAX_ASSETS][TEXT_LEN];
    int astCount = 0;

    int choice;

    do {
        printf("\n=== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ===\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        choice = readIntInRange("Enter your choice: ", 1, 6);

        switch (choice) {
        case 1:
            employeeMenu(empIds, empNames, empDepts, empBasic, empHousing,
                         empTransport, &empCount);
            break;
        case 2:
            budgetMenu(budDepts, budAllocated, budExpenditure, &budCount);
            break;
        case 3:
            supplierMenu(supIds, supNames, supEmails, supPhones, supTowns,
                         &supCount);
            break;
        case 4:
            assetMenu(astIds, astNames, astTypes, astValues, astDepts,
                      astConditions, &astCount);
            break;
        case 5:
            reportsMenu(empBasic, empHousing, empTransport, &empCount,
                        budDepts, budAllocated, budExpenditure, &budCount,
                        supIds, supNames, supEmails, supPhones, supTowns,
                        &supCount,
                        astIds, astNames, astTypes, astValues, astDepts,
                        astConditions, &astCount);
            break;
        case 6:
            printf("Thank you for using the MFMS. Goodbye.\n");
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}
