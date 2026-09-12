#ifndef ASSETS_H
#define ASSETS_H

#include "common.h"

/* Asset Management module.
   Data is kept in parallel arrays: record i is the tuple
   (ids[i], names[i], types[i], values[i], departments[i], conditions[i]). */

#define MAX_ASSETS 100

/* Adds one asset. Condition must be New, Good, Fair or Poor.
   Returns the new count (unchanged when full). */
int addAsset(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
             double values[], char departments[][TEXT_LEN],
             char conditions[][TEXT_LEN], int count);

/* Prints the full asset register. Shows a message when empty. */
void displayAssets(int ids[], const char names[][TEXT_LEN],
                   const char types[][TEXT_LEN], const double values[],
                   const char departments[][TEXT_LEN],
                   const char conditions[][TEXT_LEN], int count);

/* Searches by type or by department and prints every match.
   Returns the number of matches found. */
int searchAssets(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count);

/* Sub menu loop: add, display, search, back. */
void assetMenu(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
               double values[], char departments[][TEXT_LEN],
               char conditions[][TEXT_LEN], int *count);

#endif
