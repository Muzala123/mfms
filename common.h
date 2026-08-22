#ifndef COMMON_H
#define COMMON_H

/* Shared constants and safe input helpers.
   Every module reads user input ONLY through these functions so that
   validation and newline handling behave the same everywhere. */

#define TEXT_LEN 50

/* Loops until the user enters an integer between min and max (inclusive). */
int readIntInRange(const char *prompt, int min, int max);

/* Loops until the user enters a valid number that is not negative. */
double readDoublePositive(const char *prompt);

/* Loops until the user enters a non empty line of text. Spaces are allowed.
   The trailing newline produced by Enter is removed before returning. */
void readText(const char *prompt, char buffer[], int len);

#endif
