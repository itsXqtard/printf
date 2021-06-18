#include "my_stdio.h"
#include <stdio.h>


int my_strlen(char* str) {
    int index = 0;
    while(str[index] != '\0') {
        index++;
    }
    return index;
}

char* print_d() {
    char* c = "";
    return c;
}

char* print_o(){
    char* c = "";
    return c;
}

char* print_u() {
    char* c = "";
    return c;
}

char* print_x() {
    char* c = "";
    return c;
}

char* print_c() {
    char* c = "";
    return c;
}

char* print_s() {
    char* c = "";
    return c;
}

char* print_p() {
    char* c = "";
    return c;
}

char* (*getPrintFunction(char i, int size))(va_list) {

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

int my_printf(char * restrict format, ...) {
    
    if(format == (char*)NULLPTR) {
        return -1;
    }

    int format_len = 0;
    int index = 0;
    int buffer_len = 0;
    char *buffer;
    char* (*printFunction)(va_list);

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == NULLPTR) {
        return -1;
    }

    va_list specifiers;
    // char* current;
    va_start(specifiers, format);
    while(format[index] != '\0') {
        if(format[index] != '%') {
            buffer[buffer_len++] = format[index];
            format_len++;
        } else {
            index++;
            printFunction = getPrintFunction(format[index], SPECIFIER_SIZE);
            char* s = printFunction(specifiers);
            buffer[buffer_len++] = s[0];
            format_len++;
        }
    }
    write(1, buffer, buffer_len);
    va_end(specifiers);
    return 0;
    

}

int main() {
    my_printf("%s\n", "15");
}