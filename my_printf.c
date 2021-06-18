#include "my_stdio.h"
#include <stdio.h>

int checkBufferOverflow(char* buffer, buffer_len) {
    if(len > BUFSIZE) {
        write(1, buffer, len);
        buffer_len = 0; 
    }
    return buffer_len;
}

int my_strlen(char* str) {
    int index = 0;
    while(str[index] != '\0') {
        index++;
    }
    return index;
}

char* print_d() {
    return "";
}

char* print_o(){
    return "";
}

char* print_u() {
    return "";
}

char* print_x() {
    return "";
}

char* print_c() {
    return "";
}

char* print_s() {
    return "";
}

char print_p() {
    return "";
}

char* (*getPrintFunction(char i))(va_list) {
    
}

int my_printf(char * restrict format, ...) {
    
    if(format == (char*)NULL) {
        return -1;
    }

    int format_len = 0;
    int index = 0;
    int buffer_len = 0;

    va_list specifiers;
    char* current;
    va_start(specifiers, format);
    while(format[index] != '\0') {
        if(format[index] != '%') {
            buffer_len = checkBufferOverflow(buffer, buffer_len);
            buffer[buffer_len++] = format[index];
            format_len++;
        } else {
            index++

        }
    }
    return 0;
    

}

int main() {
    printf("%g\n",5);
}