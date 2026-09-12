#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"

/* Employee Management module.
   Data is kept in parallel arrays: record i is the tuple
   (ids[i], names[i], departments[i], basic[i], housing[i], transport[i]). */

#define MAX_EMPLOYEES 100

/* Adds one employee, prompting for all fields. Returns the new count.
   Returns the count unchanged when the register is full. */
int addEmployee(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                double basic[], double housing[], double transport[], int count);

/* Prints every employee as a table. Shows a message when empty. */
void displayEmployees(int ids[], const char names[][TEXT_LEN],
                      const char departments[][TEXT_LEN], const double basic[],
                      const double housing[], const double transport[], int count);

/* Returns the index of the employee with the given ID, or -1 if not found. */
int searchEmployee(const int ids[], int count, int id);

/* Prints one employee record, including the gross salary. */
void printEmployee(int id, const char name[], const char department[],
                   double basic, double housing, double transport);

/* Gross salary: basic + housing + transport. No deductions. */
double calculateSalary(double basic, double housing, double transport);

/* Sub menu loop: add, display, search, salary info, back. */
void employeeMenu(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                  double basic[], double housing[], double transport[], int *count);

#endif
