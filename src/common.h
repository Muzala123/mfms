#ifndef COMMON_H
#define COMMON_H



#define TEXT_LEN 50


int readIntInRange(const char *prompt, int min, int max);


double readDoublePositive(const char *prompt);


void readText(const char *prompt, char buffer[], int len);

#endif
