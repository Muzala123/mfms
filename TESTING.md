# MFMS Testing Record

Owner: Nelson Sonhi (Testing, documentation and Git coordination).
Every case below was executed against the built program. Input was fed through
the terminal and the output checked against the expected result.

## 1. Input helpers (common module)

| Case | Input | Expected | Result |
|------|-------|----------|--------|
| Non numeric menu choice | `abc` | "Invalid input. Please enter a number." | PASS |
| Out of range choice | `9` (menu allows 0 to 4) | "Please enter a number between 0 and 4." | PASS |
| Valid choice accepted | `2` | action executes | PASS |
| Non numeric money value | `abc` | "Invalid input. Please enter a number." | PASS |
| Negative money value | `-5` | "The value cannot be negative." | PASS |
| Zero money value accepted | `0` | accepted (0 is not negative) | PASS |
| Empty text field | Enter | "Input cannot be empty." | PASS |
| Text containing spaces | `ABC Office Supplies` | stored whole, length 19, no newline | PASS |

## 2. Employee module

| Case | Expected | Result |
|------|----------|--------|
| Add two employees | sequential IDs 1, 2, all fields stored | PASS |
| Display with empty register | "No employees registered yet." | PASS |
| Display with two employees | aligned table, correct gross values | PASS |
| Search existing ID 2 | found at index 1, record printed | PASS |
| Search missing ID 99 | returns not found | PASS |
| Salary information | gross = basic + housing + transport (e.g. 12000 + 2000 + 800 = 14800.00) | PASS |
| Invalid sub menu choice `9` | rejected and re-prompted | PASS |
| Register capacity | 101st add rejected with "The employee register is full" | PASS |

## 3. Budget module

| Case | Expected | Result |
|------|----------|--------|
| Add budget (Finance, N$500000) | registered, expenditure starts at 0 | PASS |
| Duplicate department | "Department Finance already has a budget." | PASS |
| Negative allocated budget | rejected | PASS |
| Add expenditure (Finance, N$420000) | expenditure accumulates | PASS |
| Expenditure for unknown department | "No department named X was found." | PASS |
| Display matches project brief example | Department/Allocated/Expenditure/Remaining/Status lines, Finance: WITHIN BUDGET, remaining 80000.00 | PASS |
| Boundary: expenditure == allocated (Water, 1000/1000) | WITHIN BUDGET | PASS |
| Over budget (Sports, 100/150) | OVER BUDGET | PASS |
| Over budget list | lists only Sports, not Finance or Water | PASS |
| Empty over budget list | "No department has exceeded its budget." | PASS |
| Invalid sub menu choice `9` | rejected and re-prompted | PASS |

## 4. Supplier module

| Case | Expected | Result |
|------|----------|--------|
| Add two suppliers | sequential IDs, all four text fields stored whole | PASS |
| Display with empty register | "No suppliers registered yet." | PASS |
| Display with suppliers | table plus name length column (19 for ABC Office Supplies) | PASS |
| Name lengths option | each name with its character count | PASS |
| Search existing name (strcmp) | found | PASS |
| Search missing name | returns not found | PASS |
| Invalid sub menu choice `9` | rejected and re-prompted | PASS |

## 5. Asset module

| Case | Expected | Result |
|------|----------|--------|
| Add asset with invalid condition "Broken" | "Condition must be New, Good, Fair or Poor." | PASS |
| Add asset with condition "Good" | accepted, all fields stored | PASS |
| Display with empty register | "No assets registered yet." | PASS |
| Display with assets | full register table | PASS |
| Search by type (Vehicles) | one match printed | PASS |
| Search with no matches | "No assets match X." | PASS |
| Invalid sub menu choice `9` | rejected and re-prompted | PASS |

## 6. Reports

| Case | Expected | Result |
|------|----------|--------|
| Employee report with empty register | "No employees registered yet." | PASS |
| Employee report, 3 employees | Total 3, Average N$10366.67, Highest N$14800.00, Lowest N$5800.00 | PASS |
| Budget report with empty register | "No budgets registered yet." | PASS |
| Budget report, 3 budgets | allocated 501100.00, expenditure 421150.00, remaining 79950.00, only Sports listed over budget | PASS |
| Supplier report | full supplier listing | PASS |
| Asset report | full asset listing | PASS |
| Reports menu navigation | all four reports reachable, 0 returns | PASS |

## 7. Integration (full walkthrough)

One continuous session through the main menu: added an employee, created the
Finance budget, recorded expenditure, added a supplier and an asset, then ran
the employee and budget reports and exited. All eight output checks passed,
including the "Goodbye" exit message.

## 8. Static checks

| Check | Expected | Result |
|-------|----------|--------|
| No direct scanf/fgets outside common.c | none | PASS |
| Full build with `-Wall -Wextra` | zero warnings | PASS |
