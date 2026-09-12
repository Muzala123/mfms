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

void printEmployee(int id, const char name[], const char department[],
                   double basic, double housing, double transport)
{
    printf("%-6d %-25s %-15s %12.2f %12.2f %12.2f %12.2f\n",
           id, name, department, basic, housing, transport,
           calculateSalary(basic, housing, transport));
}

void displayEmployees(int ids[], const char names[][TEXT_LEN],
                      const char departments[][TEXT_LEN], const double basic[],
                      const double housing[], const double transport[], int count)
{
    int i;

    if (count == 0) {
        printf("No employees registered yet.\n");
        return;
    }

    printf("--- Employee Register ---\n");
    printf("%-6s %-25s %-15s %12s %12s %12s %12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport",
           "Gross");
    for (i = 0; i < count; i++) {
        printEmployee(ids[i], names[i], departments[i], basic[i],
                      housing[i], transport[i]);
    }
}

int searchEmployee(const int ids[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}

void employeeMenu(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                  double basic[], double housing[], double transport[], int *count)
{
    int choice;
    int index;
    int id;

    for (;;) {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Employee salary information\n");
        printf("0. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 0, 4);

        if (choice == 0) {
            return;
        }

        switch (choice) {
        case 1:
            *count = addEmployee(ids, names, departments, basic, housing,
                                 transport, *count);
            break;
        case 2:
            displayEmployees(ids, names, departments, basic, housing,
                             transport, *count);
            break;
        case 3:
            if (*count == 0) {
                printf("No employees registered yet.\n");
                break;
            }
            id = readIntInRange("Employee ID to search: ", 1, MAX_EMPLOYEES);
            index = searchEmployee(ids, *count, id);
            if (index >= 0) {
                printEmployee(ids[index], names[index], departments[index],
                              basic[index], housing[index], transport[index]);
            } else {
                printf("No employee with ID %d was found.\n", id);
            }
            break;
        case 4:
            if (*count == 0) {
                printf("No employees registered yet.\n");
                break;
            }
            id = readIntInRange("Employee ID: ", 1, MAX_EMPLOYEES);
            index = searchEmployee(ids, *count, id);
            if (index >= 0) {
                printf("Employee: %s\n", names[index]);
                printf("Gross salary: N$%.2f\n",
                       calculateSalary(basic[index], housing[index],
                                       transport[index]));
            } else {
                printf("No employee with ID %d was found.\n", id);
            }
            break;
        default:
            break;
        }
    }
}
