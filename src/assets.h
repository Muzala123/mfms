#ifndef ASSETS_H
#define ASSETS_H

#include "common.h"



#define MAX_ASSETS 100


int addAsset(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
             double values[], char departments[][TEXT_LEN],
             char conditions[][TEXT_LEN], int count);

void displayAssets(int ids[], const char names[][TEXT_LEN],
                   const char types[][TEXT_LEN], const double values[],
                   const char departments[][TEXT_LEN],
                   const char conditions[][TEXT_LEN], int count);


int searchAssets(int ids[], const char names[][TEXT_LEN],
                 const char types[][TEXT_LEN], const double values[],
                 const char departments[][TEXT_LEN],
                 const char conditions[][TEXT_LEN], int count);


void assetMenu(int ids[], char names[][TEXT_LEN], char types[][TEXT_LEN],
               double values[], char departments[][TEXT_LEN],
               char conditions[][TEXT_LEN], int *count);

#endif
