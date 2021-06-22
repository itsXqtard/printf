#include "my_stdio.h"
#include <stdio.h>


static char* (*getPrintFunction(char i, int size))(va_list) {

    print_type function_list[] = {
        {'d', print_d},
        {'o', print_o},
        {'u', print_u},
        {'x', print_x},
        {'c', print_c},
        {'s', print_s},
        {'p', print_p}
    };

    for(int x = 0; x < size; x++) {
        if(function_list[x].specifier == i) {
            return function_list[x].func;
        }
    }
    return NULLPTR;
}

static void addToBuffer(char* buffer, char c, int* buffer_len, int* format_len) {
    buffer[(*buffer_len)++] = c;
    (*format_len)++;
}

static void handleFormatSpecifier(va_list ap, char specifier, char* buffer, int* format_len, int* buffer_len) {
    char* (*printFunction)(va_list);
    printFunction = getPrintFunction(specifier, SPECIFIER_SIZE);
    char* s = printFunction(ap);
    int i = 0;
    while(s[i] != '\0') {
        addToBuffer(buffer, s[i], buffer_len, format_len);
        i++;
    }
    free(s);
}

int my_printf(char * restrict format, ...) {
    
    if(format == (char*)NULLPTR) {
        return -1;
    }

    va_list ap;
    int format_len = 0, buffer_len = 0, index = 0;
    char *buffer;
    
	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == NULLPTR) {
        return -1;
    }

    va_start(ap, format);
    while(format[index] != '\0') {
        if(format[index] == '%') {
            index++;
            handleFormatSpecifier(ap, format[index], buffer, &format_len, &buffer_len);
            index++;
        } else {
            addToBuffer(buffer, format[index], &buffer_len, &format_len);
            index++;
        }
    }
    write(1, buffer, buffer_len);
    va_end(ap);
    free(buffer);
    return format_len;
    

}

int main() {
    char* nullPTR = NULL;
    char* str = malloc(sizeof(char) * 20);
    int my_size = 0;
    int size = 0;
    my_strcpy(str, "bye");
    my_size = my_printf("hello ");
    my_size += my_printf("%c %u %o %d %o %d %x %o %x %s %s %p\n", 65, -30, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);

    size = printf("hello ");
    size += printf("%c %u %o %d %o %d %x %o %x %s %s %p\n", 65, -30, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);
    printf("My size: %d\n", my_size);
    printf("size: %d\n", size);
    free(str);
}