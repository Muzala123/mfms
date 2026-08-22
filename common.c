#include <stdio.h>
#include "common.h"

/* Discards the rest of the current input line so the next read starts clean. */
static void clearLine(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* skip characters until end of line */
    }
}

int readIntInRange(const char *prompt, int min, int max)
{
    int value;
    int read;

    for (;;) {
        printf("%s", prompt);
        read = scanf("%d", &value);
        if (read != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearLine();
            continue;
        }
        clearLine();
        if (value < min || value > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }
        return value;
    }
}
