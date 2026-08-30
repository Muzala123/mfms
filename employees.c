#include <stdio.h>
#include "common.h"
#include "employees.h"

int addEmployee(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                double basic[], double housing[], double transport[], int count)
{
    if (count >= MAX_EMPLOYEES) {
        printf("The employee register is full (maximum %d employees).\n",
               MAX_EMPLOYEES);
        return count;
    }

    printf("--- Add Employee ---\n");

    /* IDs are assigned in registration order, starting from 1. */
    ids[count] = count + 1;

    readText("Name: ", names[count], TEXT_LEN);
    readText("Department: ", departments[count], TEXT_LEN);
    basic[count]     = readDoublePositive("Basic salary (N$): ");
    housing[count]   = readDoublePositive("Housing allowance (N$): ");
    transport[count] = readDoublePositive("Transport allowance (N$): ");

    printf("Employee %d added.\n", ids[count]);
    return count + 1;
}

double calculateSalary(double basic, double housing, double transport)
{
    /* Gross salary only: basic plus the two allowances. No deductions. */
    return basic + housing + transport;
}
