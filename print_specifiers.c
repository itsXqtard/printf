#include "print_specifiers.h"
/**
 * Takes an argument pointer converts it to an int 
 * and then returns as string
 * @param arg_specifier - argument pointer
 * @return signed decimal as a string
**/
char* print_d(va_list arg_specifier) {
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 10, SIGNED);
}
/**
 * Takes an argument pointer converts it to an int 
 * and then returns as string
 * @param arg_specifier - argument pointer
 * @return unsigned octal as a string
**/
char* print_o(va_list arg_specifier){
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 8, UNSIGNED);
}

/**
 * Takes an argument pointer converts it to an int 
 * and then returns as string
 * @param arg_specifier - argument pointer
 * @return unsigned decimal as a string
**/
char* print_u(va_list arg_specifier) {
    int signedInt = va_arg(arg_specifier, int);
    return my_itoa(signedInt, 10, UNSIGNED);
}
/**
 * Takes an argument pointer converts it to an int 
 * and then returns as string
 * @param arg_specifier - argument pointer
 * @return unsigned hexidecimal as a string
**/
char* print_x(va_list arg_specifier) {
    int num = va_arg(arg_specifier, int);
    return my_itoa(num, 16, UNSIGNED);
}

/**
 * Takes an argument pointer converts it to an int 
 * and then returns as string
 * @param arg_specifier - argument pointer
 * @return a character as a string
**/
char* print_c(va_list arg_specifier) {
    char* space = malloc(sizeof(char) * 2);
    int c = va_arg(arg_specifier, int);
    space[0] = c;
    space[1] = '\0';
    return space;
}

/**
 * Takes an argument pointer converts it to an char* 
 * and adds to a buffer space returns the buffer
 * @param arg_specifier - argument pointer
 * @return string
**/
char* print_s(va_list arg_specifier) {
    char* str = va_arg(arg_specifier, char*);
    if(str == (char*) NULLPTR) {
        str = "(null)";
    }
    int len = my_strlen(str);
    char* space = malloc(sizeof(char) * len + 1);
    return my_strcpy(space, str);
}

/**
 * Takes an argument pointer converts it to an long 
 * Then the long is converted to an unsigned long which gets 
 * converted the address of the signed long value to a string 
 * with a prepended "0x" to the front
 * @param arg_specifier - argument pointer
 * @return hexidecmial wih prepended 0x as a string
**/
char* print_p(va_list arg_specifier) {
    long* num = va_arg(arg_specifier, long*);
    unsigned long address = *(unsigned long*)&num;
    return my_itoa(address, 16, UNSIGNED);
}