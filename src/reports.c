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
