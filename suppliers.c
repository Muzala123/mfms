#include <stdio.h>
#include "common.h"
#include "suppliers.h"

int addSupplier(int ids[], char names[][TEXT_LEN], char emails[][TEXT_LEN],
                char phones[][TEXT_LEN], char towns[][TEXT_LEN], int count)
{
    if (count >= MAX_SUPPLIERS) {
        printf("The supplier register is full (maximum %d suppliers).\n",
               MAX_SUPPLIERS);
        return count;
    }

    printf("--- Add Supplier ---\n");

    /* Supplier IDs are assigned in registration order, starting from 1. */
    ids[count] = count + 1;

    readText("Supplier name: ", names[count], TEXT_LEN);
    readText("Email: ", emails[count], TEXT_LEN);
    readText("Telephone number: ", phones[count], TEXT_LEN);
    readText("Town/Location: ", towns[count], TEXT_LEN);

    printf("Supplier %d added.\n", ids[count]);
    return count + 1;
}
