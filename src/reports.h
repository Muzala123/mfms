#ifndef REPORTS_H
#define REPORTS_H

#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"


void employeeReport(const double basic[], const double housing[],
                    const double transport[], int count);


void budgetReport(const char departments[][TEXT_LEN], const double allocated[],
                  const double expenditure[], int count);


void supplierReport(int ids[], const char names[][TEXT_LEN],
                    const char emails[][TEXT_LEN], const char phones[][TEXT_LEN],
                    const char towns[][TEXT_LEN], int count);


void assetReport(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count);


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
                 int *assetCount);

#endif
