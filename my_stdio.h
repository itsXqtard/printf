#ifndef MY_STDIO
#define MY_STDIO

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "my_string.h"
#include "print_specifiers.h"

#define NULLPTR (void *)0
#define BUFSIZE 256
#define FEATURE_SIZE 7
#define UNSIGNED false
#define SIGNED true



int my_printf(char * restrict format, ...);

#endif