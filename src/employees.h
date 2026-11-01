#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"



#define MAX_EMPLOYEES 100


int addEmployee(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                double basic[], double housing[], double transport[], int count);


void displayEmployees(int ids[], const char names[][TEXT_LEN],
                      const char departments[][TEXT_LEN], const double basic[],
                      const double housing[], const double transport[], int count);


int searchEmployee(const int ids[], int count, int id);


void printEmployee(int id, const char name[], const char department[],
                   double basic, double housing, double transport);


double calculateSalary(double basic, double housing, double transport);


void employeeMenu(int ids[], char names[][TEXT_LEN], char departments[][TEXT_LEN],
                  double basic[], double housing[], double transport[], int *count);

#endif
