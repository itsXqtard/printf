#include "my_stdio.h"
#ifndef MY_STRING
#define MY_STRING

char* reverse_string(char* str);
int my_strlen(char* str);
char* my_strcpy(char *dest, char *src);
char* my_itoa(long num, int base, bool isSigned);
long intLen(long num, int base);

#endif