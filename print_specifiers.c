#include "print_specifiers.h"

char* print_d(va_list arg_specifier) {
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 10, SIGNED);
}

char* print_o(va_list arg_specifier){
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 8, UNSIGNED);
}


char* print_u(va_list arg_specifier) {
    int signedInt = va_arg(arg_specifier, int);
    return my_itoa(signedInt, 10, UNSIGNED);
}

char* print_x(va_list arg_specifier) {
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 16, UNSIGNED);
}

char* print_c(va_list arg_specifier) {
    char* space = malloc(sizeof(char) * 2);
    int c = va_arg(arg_specifier, int);
    space[0] = c;
    space[1] = '\0';
    return space;
}

char* print_s(va_list arg_specifier) {
    char* str = va_arg(arg_specifier, char*);
    if(str == (char*) NULLPTR) {
        str = "(null)";
    }
    int len = my_strlen(str);
    char* space = malloc(sizeof(char) * len + 1);
    return my_strcpy(space, str);
}

char* print_p(va_list arg_specifier) {
    long* num = va_arg(arg_specifier, long*);
    unsigned long address = *(unsigned long*)&num;
    return my_itoa(address, 16, UNSIGNED);
}