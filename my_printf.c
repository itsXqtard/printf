#include "my_stdio.h"
#include <stdio.h>



char* print_d(va_list specifiers) {
    int num = va_arg(specifiers, int);
    return my_itoa(num, 10, SIGNED);
}

char* print_o(va_list specifiers){
    int num = va_arg(specifiers, int);
    return my_itoa(num, 8, UNSIGNED);
}


char* print_u(va_list specifiers) {
    int signedInt = va_arg(specifiers, int);
    return my_itoa(signedInt, 10, UNSIGNED);
}

char* print_x(va_list specifiers) {
    int num = va_arg(specifiers, int);
    return my_itoa(num, 16, UNSIGNED);
}

char* print_c(va_list specifiers) {
    char* space = malloc(sizeof(char) * 2);
    int c = va_arg(specifiers, int);
    space[0] = c;
    space[1] = '\0';
    return space;
}

char* print_s(va_list specifiers) {
    char* str = va_arg(specifiers, char*);
    if(str == (char*) NULLPTR) {
        str = "(null)";
    }
    int len = my_strlen(str);
    char* space = malloc(sizeof(char) * len + 1);
    return my_strcpy(space, str);
}

char* print_p(va_list specifiers) {
    long* num = va_arg(specifiers, long*);
    unsigned long address = *(unsigned long*)&num;
    return my_itoa(address, 16, UNSIGNED);
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

    va_start(specifiers, format);
    while(format[index] != '\0') {
        if(format[index] == '%') {
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
        } else {
            buffer[buffer_len++] = format[index++];
            format_len++;
        }
    }
    write(1, buffer, buffer_len);
    va_end(specifiers);
    free(buffer);
    return format_len;
    

}

int main() {
    char* nullPTR = NULL;
    char* str = malloc(sizeof(char) * 20);
    my_strcpy(str, "bye");
    int my_size = my_printf("hello %u %o %d %o %d %x %o %x %s %s %p\n", -8, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);
    int size = printf("hello %u %o %d %o %d %x %o %x %s %s %p\n", -8, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);
    printf("My size: %d\n", my_size);
    printf("size: %d\n", size);
    free(str);
}