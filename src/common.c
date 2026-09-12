#include <stdio.h>
#include <string.h>
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

double readDoublePositive(const char *prompt)
{
    double value;
    int read;

    for (;;) {
        printf("%s", prompt);
        read = scanf("%lf", &value);
        if (read != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearLine();
            continue;
        }
        clearLine();
        if (value < 0) {
            printf("The value cannot be negative.\n");
            continue;
        }
        return value;
    }
}

void readText(const char *prompt, char buffer[], int len)
{
    for (;;) {
        printf("%s", prompt);
        if (fgets(buffer, len, stdin) == NULL) {
            continue; /* input stream closed, try again */
        }
        if (strchr(buffer, '\n') == NULL) {
            clearLine(); /* line longer than the buffer, discard the rest */
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Input cannot be empty.\n");
            continue;
        }
        return;
    }
}
