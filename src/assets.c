#include <stdio.h>
#include <string.h>
#include "common.h"
#include "assets.h"

/* The condition field accepts only these four values. */
static const char *CONDITIONS[4] = { "New", "Good", "Fair", "Poor" };

int addAsset(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
             double values[], char departments[][TEXT_LEN],
             char conditions[][TEXT_LEN], int count)
{
    int i;
    int validCondition;

    if (count >= MAX_ASSETS) {
        printf("The asset register is full (maximum %d assets).\n",
               MAX_ASSETS);
        return count;
    }

    printf("--- Add Asset ---\n");

    /* Asset IDs are assigned in registration order, starting from 1. */
    ids[count] = count + 1;

    readText("Asset name: ", names[count], TEXT_LEN);
    readText("Asset type: ", types[count], TEXT_LEN);
    values[count] = readDoublePositive("Purchase value (N$): ");
    readText("Department: ", departments[count], TEXT_LEN);

    /* Only the four listed conditions are accepted. */
    validCondition = 0;
    while (!validCondition) {
        readText("Condition (New/Good/Fair/Poor): ", conditions[count], TEXT_LEN);
        for (i = 0; i < 4; i++) {
            if (strcmp(conditions[count], CONDITIONS[i]) == 0) {
                validCondition = 1;
            }
        }
        if (!validCondition) {
            printf("Condition must be New, Good, Fair or Poor.\n");
        }
    }

    printf("Asset %d added.\n", ids[count]);
    return count + 1;
}
