#include <stdio.h>
#include "reports.h"

void employeeReport(const double basic[], const double housing[],
                    const double transport[], int count)
{
    int i;
    double salary;
    double total = 0.0;
    double average;
    double highest;
    double lowest;

    if (count == 0) {
        printf("No employees registered yet.\n");
        return;
    }

    highest = calculateSalary(basic[0], housing[0], transport[0]);
    lowest = highest;

    for (i = 0; i < count; i++) {
        salary = calculateSalary(basic[i], housing[i], transport[i]);
        total += salary;
        if (salary > highest) {
            highest = salary;
        }
        if (salary < lowest) {
            lowest = salary;
        }
    }
    average = total / count;

    printf("--- EMPLOYEE REPORT ---\n");
    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", average);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(const char departments[][TEXT_LEN], const double allocated[],
                  const double expenditure[], int count)
{
    int i;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int overCount = 0;

    if (count == 0) {
        printf("No budgets registered yet.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        totalAllocated += allocated[i];
        totalExpenditure += expenditure[i];
    }

    printf("--- BUDGET REPORT ---\n");
    printf("Total allocated budget: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining budget: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("Departments exceeding budget:\n");
    for (i = 0; i < count; i++) {
        if (expenditure[i] > allocated[i]) {
            printf("  %s: spent N$%.2f of N$%.2f\n", departments[i],
                   expenditure[i], allocated[i]);
            overCount++;
        }
    }
    if (overCount == 0) {
        printf("  None.\n");
    }
}

void supplierReport(int ids[], const char names[][TEXT_LEN],
                    const char emails[][TEXT_LEN], const char phones[][TEXT_LEN],
                    const char towns[][TEXT_LEN], int count)
{
    printf("--- SUPPLIER REPORT ---\n");
    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }
    displaySuppliers(ids, names, emails, phones, towns, count);
}

void assetReport(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count)
{
    printf("--- ASSET REPORT ---\n");
    if (count == 0) {
        printf("No assets registered yet.\n");
        return;
    }
    displayAssets(ids, names, types, values, departments, conditions, count);
}

void reportsMenu(double basic[], double housing[], double transport[],
                 int *employeeCount,
                 char budgetDepartments[][TEXT_LEN], double allocated[],
                 double expenditure[], int *budgetCount,
                 int supplierIds[], char supplierNames[][TEXT_LEN],
                 char emails[][TEXT_LEN], char phones[][TEXT_LEN],
                 char towns[][TEXT_LEN], int *supplierCount,
                 int assetIds[], char assetNames[][TEXT_LEN],
                 char types[][TEXT_LEN], double values[],
                 char assetDepartments[][TEXT_LEN], char conditions[][TEXT_LEN],
                 int *assetCount)
{
    int choice;

    for (;;) {
        printf("\n--- REPORTS ---\n");
        printf("1. Employee report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Asset report\n");
        printf("0. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 0, 4);

        if (choice == 0) {
            return;
        }

        switch (choice) {
        case 1:
            employeeReport(basic, housing, transport, *employeeCount);
            break;
        case 2:
            budgetReport(budgetDepartments, allocated, expenditure, *budgetCount);
            break;
        case 3:
            supplierReport(supplierIds, supplierNames, emails, phones, towns,
                           *supplierCount);
            break;
        case 4:
            assetReport(assetIds, assetNames, types, values, assetDepartments,
                        conditions, *assetCount);
            break;
        default:
            break;
        }
    }
}
