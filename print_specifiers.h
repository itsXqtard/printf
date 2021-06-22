#include "my_stdio.h"
#ifndef PRINT_SPECIFIERS
#define PRINT_SPECIFIERS

typedef struct print_specifier
{
	char specifier;
	char* (*func)(va_list);
} print_type;

char* print_d(va_list arg_specifier);
char* print_o(va_list arg_specifier);
char* print_u(va_list arg_specifier);
char* print_x(va_list arg_specifier);
char* print_c(va_list arg_specifier);
char* print_s(va_list arg_specifier);
char* print_p(va_list arg_specifier);

#endif