#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "common.h"

/* Supplier Management module (based on the Week 7 laboratory).
   Data is kept in parallel arrays: record i is the tuple
   (ids[i], names[i], emails[i], phones[i], towns[i]). */

#define MAX_SUPPLIERS 100

/* Adds one supplier, prompting for name, email, phone and town.
   Returns the new count (unchanged when full). */
int addSupplier(int ids[], char names[][TEXT_LEN], char emails[][TEXT_LEN],
                char phones[][TEXT_LEN], char towns[][TEXT_LEN], int count);

/* Prints every supplier with the length of each supplier name (strlen). */
void displaySuppliers(int ids[], const char names[][TEXT_LEN],
                      const char emails[][TEXT_LEN], const char phones[][TEXT_LEN],
                      const char towns[][TEXT_LEN], int count);

/* Exact name search using strcmp. Returns the index or -1 when not found. */
int searchSupplier(const char names[][TEXT_LEN], int count, const char target[]);

/* Prints one supplier record. */
void printSupplier(int id, const char name[], const char email[],
                   const char phone[], const char town[]);

/* Prints every supplier name with its length (Week 7 lab task 2). */
void showNameLengths(const char names[][TEXT_LEN], int count);

/* Sub menu loop: add, display, search, name lengths, back (lab task 6). */
void supplierMenu(int ids[], char names[][TEXT_LEN], char emails[][TEXT_LEN],
                  char phones[][TEXT_LEN], char towns[][TEXT_LEN], int *count);

#endif
