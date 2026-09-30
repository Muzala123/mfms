# Individual Contribution Record

Repository: github.com/SilvioIvanio/mfms. Every member's commit list can be
verified with `git log --author=<username> --oneline`. Testing evidence is in
TESTING.md at the repository root.

---

## Member 1

- Student name: Edmilson Ventura
- Student number: 225162369
- Assigned responsibility: Project leader, Employee Management
- Functions/modules developed: src/employees.h and src/employees.c
  (addEmployee, printEmployee, displayEmployees, searchEmployee,
  calculateSalary, employeeMenu)
- GitHub contribution (6 commits): employee module header, addEmployee with
  validation and capacity check, calculateSalary returning gross salary,
  displayEmployees table, searchEmployee lookup by ID, employee management
  sub menu with validation
- Testing performed: employee module checklist in TESTING.md section 2,
  including the capacity limit and the salary calculation case (12000 + 2000
  + 800 = 14800.00)

## Member 2

- Student name: Joseph Penelao
- Student number: 226172376
- Assigned responsibility: Budget Management
- Functions/modules developed: src/budget.h and src/budget.c (addBudget,
  addExpenditure, displayBudgets, listOverBudget, budgetMenu)
- GitHub contribution (7 commits): budget module header, addBudget with
  duplicate department rejection, addExpenditure with department lookup,
  displayBudgets in the project brief format, listOverBudget with the exact
  boundary rule, budget management sub menu with validation, cleanup of
  duplicated budget functions after the folder reorganisation
- Testing performed: budget module checklist in TESTING.md section 3,
  including the duplicate department case and the boundary case where
  expenditure equals the allocation (within budget)

## Member 3

- Student name: Stephan
- Student number: 224094580
- Assigned responsibility: Supplier Management
- Functions/modules developed: src/suppliers.h and src/suppliers.c
  (addSupplier, printSupplier, displaySuppliers, showNameLengths,
  searchSupplier, supplierMenu)
- GitHub contribution (4 commits): addSupplier with validated text fields,
  supplier display with name lengths, searchSupplier using strcmp, supplier
  sub menu per the Week 7 laboratory
- Testing performed: supplier module checklist in TESTING.md section 4,
  including the search hit and miss cases and text fields containing spaces

## Member 4

- Student name: Filiph Visesse
- Student number: 225173069
- Assigned responsibility: Asset Management
- Functions/modules developed: src/assets.h and src/assets.c (addAsset,
  displayAssets, searchAssets, assetMenu)
- GitHub contribution (3 commits): asset register display with empty state,
  asset search by type or department, asset sub menu with validation
- Testing performed: asset module checklist in TESTING.md section 5,
  including the rejected condition "Broken" and the search with no matches

## Member 5

- Student name: Matias Kalilo
- Student number: 226075621
- Assigned responsibility: Reports
- Functions/modules developed: src/reports.h and src/reports.c
  (employeeReport, budgetReport, supplierReport, assetReport, reportsMenu)
- GitHub contribution (6 commits): employee report with average, highest and
  lowest salary; budget report with totals and over budget list; supplier and
  asset reports; reports sub menu; two cleanups removing parameters the
  report functions did not use
- Testing performed: reports checklist in TESTING.md section 6, verifying the
  statistics against hand computed values (average N$10366.67, highest
  N$14800.00, lowest N$5800.00 for the three employee test set)

## Member 6

- Student name: Ester Micheal
- Student number: 2240691012
- Assigned responsibility: Functions, integration and validation
- Functions/modules developed: src/common.h and src/common.c (readIntInRange,
  readDoublePositive, readText, clearLine, inputClosed) and src/main.c (main
  menu that owns all data arrays and joins the modules)
- GitHub contribution (5 commits): common header with shared constants,
  readIntInRange, readDoublePositive, readText, graceful exit when the input
  stream ends; plus the main menu integration
- Testing performed: input validation cases in TESTING.md section 1 and the
  end of input case; verified that no module calls scanf or fgets directly
  (TESTING.md section 8)

## Member 7

- Student name: Nelson Sonhi
- Student number: 224088882
- Assigned responsibility: Testing, documentation and Git coordination
- Functions/modules developed: repository setup, .gitignore, .vscode build
  tasks, README.md, TESTING.md, technical report and contribution record
  coordination
- GitHub contribution (9 commits): repository initialisation, gitignore
  rules, the src folder organisation with updated build instructions, README
  completion, testing record and documentation, VS Code build task
  documentation
- Testing performed: consolidated the checklists in TESTING.md, ran the full
  integration walkthrough in section 7 and the static checks in section 8
  (zero warning build, no direct input calls outside the common module)
