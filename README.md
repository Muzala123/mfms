# Municipal Financial Management System (MFMS)

Windhoek Municipality, Namibia. PAP521S Programming in Practice, Project A.

A menu driven console application, written in ANSI C (C99), that manages a
municipality's employees, departmental budgets, suppliers and assets, and
produces summary reports. Data is kept in memory for the duration of a session.

## Group [Number]

| Student No. | Name | Responsibility |
|-------------|------|----------------|
| 225162369 | Edmilson Ventura (Project Leader) | Employee Management |
| 226172376 | Joseph Penelao | Budget Management |
| 224094580 | Stephan | Supplier Management |
| 225173069 | Filiph Visesse | Asset Management |
| 226075621 | Matias Kalilo | Reports |
| 2240691012 | Ester Micheal | Functions, integration & validation |
| 224088882 | Nelson Sonhi | Testing, documentation & Git coordination |

## System Features

1. **Main menu** with six options: Employee, Budget, Supplier and Asset
   Management, Reports, and Exit.
2. **Employee Management:** add employees (ID, name, department, basic salary,
   housing and transport allowances), display the register, search by ID, and
   show gross salary information (basic + housing + transport).
3. **Budget Management:** register departmental budgets, record expenditure,
   display remaining budget and status (WITHIN BUDGET / OVER BUDGET), and list
   every department that has exceeded its allocation.
4. **Supplier Management:** add suppliers (ID, name, email, telephone, town),
   display the register with name lengths, and search suppliers by name.
5. **Asset Management:** maintain an asset register (ID, name, type, purchase
   value, department, condition: New/Good/Fair/Poor), display and search by
   type or department.
6. **Reports:** employee salary statistics (total, average, highest, lowest),
   budget totals and departments over budget, supplier listing, asset listing.
7. **Input validation:** non numeric input, negative money values, empty text
   fields, invalid menu choices and duplicate department names are all rejected
   with clear messages and re-prompted.

## Compilation

```bash
gcc -std=c99 -Wall -Wextra -Isrc -o mfms src/main.c src/common.c src/employees.c src/budget.c src/suppliers.c src/assets.c src/reports.c
```

The build completes with zero warnings.

In VS Code the same build is available as the default build task
(`.vscode/tasks.json`): open the menu Terminal, then Run Build Task, and run
`./mfms` in the terminal afterwards. Do not use the Run button on a single
file: a multi file C project must compile all `.c` files together, so building
`main.c` alone fails at the linking stage.

## How to Run

```bash
./mfms
```

Then choose a number from the main menu. Each module opens its own sub menu;
choose 0 to return to the main menu, and choose 6 (Exit) to close the system.

## Project Structure

```
src/
├── main.c          # main menu and program entry point
├── common.c/.h     # shared constants and validated input helpers
├── employees.c/.h  # employee module
├── budget.c/.h     # budget module
├── suppliers.c/.h  # supplier module
├── assets.c/.h     # asset module
└── reports.c/.h    # reports module
TESTING.md          # manual test checklists and results
README.md           # this file
```
