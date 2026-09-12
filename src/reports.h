#ifndef REPORTS_H
#define REPORTS_H

#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

/* Reports module. Reports own no data: every function receives the module
   arrays and counts as parameters, so reports always show current data. */

/* Total employees, average, highest and lowest gross salary. */
void employeeReport(const int ids[], const char names[][TEXT_LEN],
                    const char departments[][TEXT_LEN], const double basic[],
                    const double housing[], const double transport[], int count);

/* Total allocated, total expenditure, remaining, departments over budget. */
void budgetReport(const char departments[][TEXT_LEN], const double allocated[],
                  const double expenditure[], int count);

/* Full supplier listing. */
void supplierReport(int ids[], const char names[][TEXT_LEN],
                    const char emails[][TEXT_LEN], const char phones[][TEXT_LEN],
                    const char towns[][TEXT_LEN], int count);

/* Full asset listing. */
void assetReport(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count);

/* Reports sub menu loop. */
void reportsMenu(int employeeIds[], char employeeNames[][TEXT_LEN],
                 char employeeDepartments[][TEXT_LEN], double basic[],
                 double housing[], double transport[], int *employeeCount,
                 char budgetDepartments[][TEXT_LEN], double allocated[],
                 double expenditure[], int *budgetCount,
                 int supplierIds[], char supplierNames[][TEXT_LEN],
                 char emails[][TEXT_LEN], char phones[][TEXT_LEN],
                 char towns[][TEXT_LEN], int *supplierCount,
                 int assetIds[], char assetNames[][TEXT_LEN],
                 char types[][TEXT_LEN], double values[],
                 char assetDepartments[][TEXT_LEN], char conditions[][TEXT_LEN],
                 int *assetCount);

#endif
