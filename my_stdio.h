#ifndef MY_STDIO
#define MY_STDIO

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "my_string.h"

#define NULLPTR (void *)0
#define BUFSIZE 256
#define SPECIFIER_SIZE 7
#define UNSIGNED false
#define SIGNED true

typedef struct print_specifier
{
	char specifier;
	char* (*func)(va_list);
} print_type;



int my_printf(char * restrict format, ...);

#endif