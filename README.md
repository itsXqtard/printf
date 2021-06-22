# my_printf

The `my_printf()` function produce output according to a format similar to that of printf in the stdio library. The `my_printf()` functions write output to stdout, the standard output stream just like `printf()`

# Features and Information
`doux` The int (or appropriate variant) argument is converted to signed decimal (`d`). unsigned octal (`o`), unsigned decimal (`u`), unsigned hexadecimal (`x`).<br>
`c` The int argument is converted to an unsigned char, and the resulting character is written.<br>
`s` The `char *` argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.<br>
`p` The `void *` pointer argument is printed in hexadecimal.<br>

When reading string to stdin the current buffer size is set to `256` bytes of space.


# Example main
```
#include <stdio.h>
  
int main() {
    char* nullPTR = NULL;
    char* str = malloc(sizeof(char) * 20);
    int my_size = 0;
    int size = 0;
    my_strcpy(str, "bye");
    my_size = my_printf("hello ");
    my_size += my_printf("%c %u %o %d %o %d %x %o %x %s %s %p\n", 65, -30, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);

    size = printf("hello ");
    size    +=    printf("%c %u %o %d %o %d %x %o %x %s %s %p\n", 65, -30, 8, 8, -8, -8, -15, 'c', 'd', "hello", nullPTR, str);
    printf("My size: %d\n", my_size);
    printf("size: %d\n", size);
    free(str);
}
```

