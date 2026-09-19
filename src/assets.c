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

void displayAssets(int ids[], const char names[][TEXT_LEN],
                   const char types[][TEXT_LEN], const double values[],
                   const char departments[][TEXT_LEN],
                   const char conditions[][TEXT_LEN], int count)
{
    int i;

    if (count == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("--- Asset Register ---\n");
    printf("%-6s %-20s %-12s %12s %-15s %-8s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %-12s %12.2f %-15s %-8s\n",
               ids[i], names[i], types[i], values[i], departments[i],
               conditions[i]);
    }
}

int searchAssets(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count)
{
    char target[TEXT_LEN];
    int field;
    int i;
    int matches = 0;

    if (count == 0) {
        printf("No assets registered yet.\n");
        return 0;
    }

    field = readIntInRange("Search by 1) Type or 2) Department: ", 1, 2);
    readText("Search term: ", target, TEXT_LEN);

    for (i = 0; i < count; i++) {
        if ((field == 1 && strcmp(types[i], target) == 0) ||
            (field == 2 && strcmp(departments[i], target) == 0)) {
            printf("%-6d %-20s %-12s %12.2f %-15s %-8s\n",
                   ids[i], names[i], types[i], values[i], departments[i],
                   conditions[i]);
            matches++;
        }
    }
    if (matches == 0) {
        printf("No assets match %s.\n", target);
    }
    return matches;
}

void assetMenu(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
               double values[], char departments[][TEXT_LEN],
               char conditions[][TEXT_LEN], int *count)
{
    int choice;

    for (;;) {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search assets\n");
        printf("0. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 0, 3);

        if (choice == 0) {
            return;
        }

        switch (choice) {
        case 1:
            *count = addAsset(ids, names, types, values, departments,
                              conditions, *count);
            break;
        case 2:
            displayAssets(ids, names, types, values, departments,
                          conditions, *count);
            break;
        case 3:
            searchAssets(ids, names, types, values, departments,
                         conditions, *count);
            break;
        default:
            break;
        }
    }
}
