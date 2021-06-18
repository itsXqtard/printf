#ifndef MY_STDIO
#define MY_STDIO

#include <stdarg.h>

#define NULL (void *)0
#define BUFSIZE 256

typedef struct print_specifier
{
	char *specifier;
	int (*func)(va_list);
} print_type;



int my_printf(char * restrict format, ...);

#endif