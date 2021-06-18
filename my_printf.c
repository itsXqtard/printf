#include "my_stdio.h"
#include <stdio.h>



char* print_d(va_list specifiers) {
    char* c = malloc(sizeof(char) * BUFSIZE);
    int num = va_arg(specifiers, int);
    return my_itoa(num, c, 10, SIGNED);
}

char* print_o(va_list specifiers){
    char* c = malloc(sizeof(char) * BUFSIZE);
    int num = va_arg(specifiers, int);
    return my_itoa(num, c, 8, UNSIGNED);
}


char* print_u(va_list specifiers) {
    char* c = malloc(sizeof(char) * BUFSIZE);
    int signedInt = va_arg(specifiers, int);
    return my_itoa(signedInt, c, 10, UNSIGNED);
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

    int format_len = 0, buffer_len = 0;
    int index = 0;
    char *buffer;
    va_list specifiers;

    char* (*printFunction)(va_list);

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == NULLPTR) {
        return -1;
    }

    
    // char* current;
    va_start(specifiers, format);
    while(format[index] != '\0') {
        if(format[index] != '%') {
            buffer[buffer_len++] = format[index++];
            format_len++;
        } else {
            index++;
            printFunction = getPrintFunction(format[index], SPECIFIER_SIZE);
            char* s = printFunction(specifiers);
            int i = 0;
            while(s[i] != '\0') {
                buffer[buffer_len++] = s[i];
                format_len++;
                i++;
            }
            free(s);
            index++;
        }
    }
    write(1, buffer, buffer_len);
    va_end(specifiers);
    return 0;
    

}

int main() {
    my_printf("hello %u %o %d %o %d\n", -8, 8, 8, -8, -8);
    printf("hello %u %o %d %o %d", -8, 8, 8, -8, -8);
}