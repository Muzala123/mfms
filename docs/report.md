# Technical Report: Municipal Financial Management System

Course: PAP521S Programming in Practice, Project A, NUST.
Maximum 5 pages when exported to PDF. All sections below follow the required
structure from the project brief. Sections marked [EXPAND] need the group's own
words before submission.

## 1. Introduction

The Municipal Financial Management System (MFMS) is a menu driven console
application developed in ANSI C (C99) as the foundation version of a municipal
record system for Project A. It manages employees, departmental budgets,
suppliers and municipal assets, and produces summary reports. [EXPAND: one or
two sentences on why municipalities need such a system.]

## 2. Problem Description

Municipalities record large amounts of recurring information: employee details
and salaries, departmental budgets and expenditure, supplier contacts and
municipal assets such as vehicles and computers. Doing this by hand is slow and
error prone. The project required a foundation system that demonstrates the
INPUT, PROCESSING, STORAGE, SEARCH, CALCULATION and OUTPUT cycle using only the
C concepts covered in Weeks 1 to 8 of the course.

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
- Employee module: add, display, search by ID, gross salary information.
- Budget module: budgets per department, expenditure, remaining budget,
  WITHIN/OVER BUDGET status, over budget department list.
- Supplier module: add, display with name lengths, search by name.
- Asset module: add, display, search by type or department.
- Reports: employee statistics, budget totals, supplier and asset listings.
- Validation in every module through shared input helpers.

## 5. Program Design

The system is split into seven modules, one pair of .c/.h files each:

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
`ids[]`, `names[]`, `basic[]`) with a count variable, because structs are not
part of the Weeks 1 to 8 syllabus. Every module exposes its own sub menu and
receives its arrays as function parameters, so only main.c joins the modules
together. All user input passes through the common module helpers
(`readIntInRange`, `readDoublePositive`, `readText`), which makes validation
identical everywhere. Reports own no data: they receive the arrays and counts
as parameters and print summaries. [EXPAND: optionally add a hand drawn module
diagram.]

## 6. Challenges Encountered

1. Mixing numeric input with text input: scanf leaves the Enter key in the
   input buffer, which made later fgets calls read empty lines.
2. Choosing a data model without structs: several related values per record
   had to stay together.
3. String comparison in searches returned false matches.
4. Distinguishing exactly at budget from over budget.
5. Keeping a single consistent style across seven modules written by seven
   different students.
6. Coordinating parallel development on one repository.

## 7. Solutions Implemented

1. All numeric reads are followed by a buffer clearing routine, and all text
   reads use fgets with the trailing newline removed, so the two input styles
   never interfere.
2. Records are stored in parallel arrays, where the same index across several
   arrays describes one record, exactly as practised in the Week 5 and 6
   laboratory.
3. Name searches use strcmp from string.h with the newline stripped first, so
   comparisons are exact.
4. The budget status uses an explicit rule: expenditure equal to the allocated
   budget counts as WITHIN BUDGET, and only strictly greater expenditure is
   reported as OVER BUDGET.
5. Shared constants and input helpers live in common.h and common.c, every
   function has a declaration in its module header, and every commit was
   reviewed before push.
6. Each module was built task by task with one commit per task attributed to
   the member responsible for that module, and testing was consolidated in
   TESTING.md.

## 8. Conclusion

Project A delivers a working foundation MFMS that demonstrates input,
processing, storage, search, calculation and output using the C concepts from
the first eight weeks. The module structure was deliberately kept simple so
that Project B can extend the system, for example with file storage, editing
and deleting of records, or additional reports. [EXPAND: group reflection.]
