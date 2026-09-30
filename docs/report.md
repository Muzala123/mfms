# Technical Report: Municipal Financial Management System

Course: PAP521S Programming in Practice, Project A, Namibia University of
Science and Technology. Group repository: github.com/SilvioIvanio/mfms.
Maximum 5 pages when exported to PDF.

## 1. Introduction

The Municipal Financial Management System (MFMS) is a menu driven console
application developed in ANSI C (C99) as the foundation version of a municipal
record system. Municipalities handle large volumes of recurring information
every day: employee salaries, departmental budgets, supplier contacts and
municipal assets such as vehicles and computers. Recording this by hand is
slow, repetitive and error prone, which is exactly the kind of problem
software solves well. Project A delivers the first working version of such a
system using only the C programming concepts covered in Weeks 1 to 8 of the
course, and is designed to be extended in Project B.

## 2. Problem Description

A municipality must answer practical questions continuously: how many
employees exist and what do they cost; which departments are inside their
budget and which have exceeded it; which suppliers exist and how can they be
contacted; what assets does the municipality own and in what condition are
they. Keeping these records on paper or in scattered files makes each question
slow to answer and easy to answer wrongly. The project brief required a
foundation system that demonstrates the INPUT, PROCESSING, STORAGE, SEARCH,
CALCULATION and OUTPUT cycle: the user inputs data, the program validates and
processes it, stores it in memory for the session, supports searching,
performs calculations, and outputs formatted tables and reports.

## 3. System Objectives

1. Provide a clear, menu driven interface with six main options.
2. Store employee, budget, supplier and asset records in memory.
3. Validate every input: numbers, money values, text fields and menu choices.
4. Support searching in each module (by ID, name, type or department).
5. Calculate gross salaries, budget balances and summary statistics.
6. Produce employee, budget, supplier and asset reports.
7. Be simple and modular so Project B can extend it.

## 4. System Features

- Main menu with Employee, Budget, Supplier, Asset, Reports and Exit.
- Employee module: add, display, search by ID, gross salary information
  (basic salary plus housing and transport allowances, no deductions).
- Budget module: budgets per department, expenditure recording, remaining
  budget, WITHIN/OVER BUDGET status, and a list of departments over budget.
- Supplier module: add, display with name lengths, search by name.
- Asset module: add, display, search by type or department, with a condition
  field restricted to New, Good, Fair or Poor.
- Reports: employee salary statistics (total, average, highest, lowest),
  budget totals with over budget departments, supplier listing, asset listing.
- Validation in every module through shared input helpers: non numeric input,
  negative money values, empty text fields, invalid menu choices, duplicate
  department names and end of input are all handled without crashing.

## 5. Program Design

The system is split into seven modules, one pair of .c and .h files each:

```
main.c          main menu loop, owns all data arrays
common          shared constants and validated input helpers
employees       employee records in parallel arrays
budget          department budgets in parallel arrays
suppliers       supplier records in parallel arrays
assets          asset records in parallel arrays
reports         reads the module arrays and prints summaries
```

Data model: each module keeps its records in parallel arrays (for example
`ids[]`, `names[]`, `basic[]`) with a count variable, where the same index
across several arrays describes one record. This model was chosen because
structs are not part of the Weeks 1 to 8 syllabus, and it mirrors the
technique practised in the Week 5 and 6 laboratory. Every module exposes its
own sub menu and receives its arrays as function parameters, so only main.c
joins the modules together. All user input passes through the common module
helpers (`readIntInRange`, `readDoublePositive`, `readText`), which makes
validation identical everywhere and solves the scanf/fgets newline problem in
one place. Reports own no data: they receive the arrays and counts as
parameters and print summaries, so a report always reflects current data.

```
main menu
  |
  +-- employeeMenu -- calculateSalary
  +-- budgetMenu
  +-- supplierMenu
  +-- assetMenu
  +-- reportsMenu -- employeeReport, budgetReport, supplierReport, assetReport
```

## 6. Challenges Encountered

1. Mixing numeric and text input: scanf leaves the Enter key in the input
   buffer, so a following fgets read an empty line and validation failed.
2. Choosing a data model without structs: several related values per record
   had to stay together and be passed between functions.
3. String comparison in searches: comparing character arrays with the ==
   operator compares addresses, not content, so searches returned false
   results; a trailing newline also made equal names unequal.
4. The budget boundary: deciding whether expenditure exactly equal to the
   allocation is inside or over budget.
5. Keeping one consistent style across seven modules written by seven
   different students working in parallel.
6. End of input: if the input stream closes at a prompt, scanf keeps failing
   forever, which would hang the program.
7. Coordinating work in one repository while several members committed task by
   task.

## 7. Solutions Implemented

1. All numeric reads are followed by a buffer clearing routine, and all text
   reads use fgets with the trailing newline removed, so the two input styles
   never interfere. The helpers live in one module, so the fix was written
   once and used everywhere.
2. Records are stored in parallel arrays, where the same index across several
   arrays describes one record; adding a record writes into index `count` and
   then increments it.
3. Name searches use strcmp from string.h after the newline is stripped, so
   comparisons are exact.
4. An explicit documented rule: expenditure equal to the allocated budget
   counts as WITHIN BUDGET, and only strictly greater expenditure is reported
   as OVER BUDGET.
5. Shared constants and helpers live in common.h and common.c, every function
   has a declaration in its module header, the whole project compiles with
   `-Wall -Wextra` at zero warnings, and every commit was reviewed before
   push.
6. The helpers detect end of input explicitly, print a closing message and
   exit the system cleanly; this case was found by the capacity test and is
   documented in TESTING.md.
7. Work was split one commit per task, each commit attributed to the member
   responsible for that module, with testing consolidated in TESTING.md and
   the repository history reviewed together before the demonstration.

## 8. Conclusion

Project A delivers a working foundation MFMS that demonstrates input,
processing, storage, search, calculation and output using the C concepts from
the first eight weeks. The parallel array data model, the shared validation
helpers and the strict module boundaries keep the code simple and readable,
and the test record shows that every module behaves correctly at the edges,
not only in the happy path. Because the modules communicate only through
clearly declared functions, Project B can extend the system with file storage,
editing and deleting of records, additional reports or new modules without
rewriting the foundation. The group learned the most from the integration
phase, where small per module decisions (such as how the newline is stripped,
or what counts as over budget) had to agree across seven modules.
