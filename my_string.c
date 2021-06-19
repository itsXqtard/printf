#include "my_string.h"

char* reverse_string(char* str)
{
    int len= my_strlen(str);
    for(int index = 0; index < len / 2; index++){
        char current = str[index];
        char swap = str[len - 1 - index];
        str[index] = swap;
        str[len - 1 - index] = current;
    }
    return str;
}

char* my_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = src[x];
	return (dest);
}

int my_strlen(char* str) {
    int index = 0;
    while(str[index] != '\0') {
        index++;
    }
    return index;
}

long intLen(long num, int base) {
    int len = 0;
    if(num < 0) {
        num = -num;
        len = 2;
    }
    if(!num) {
        return 1;
    }
    for(; num != 0; ++len) {
        num /= base;
    }
    return len;
}

char* my_itoa(long num, int base, bool isSigned)
{
    long num_copy = num;
    int i = 0, isNegative = 0;
    int len = intLen(num, base);
    char* str = malloc(sizeof(char) * len + 40);
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
  
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10 && isSigned)
    {
        isNegative = 1;
        num = -num;
    }

    if(num < 0 && !isSigned) {
        num = (UINT_MAX + num) + 1;
    }
    
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if(num_copy > UINT_MAX) {
        str[i++]= 'x';
        str[i++]= '0';
    }
  
    // If number is negative, append '-'
    if (isNegative && isSigned)
        str[i++] = '-';
    
    
    str[i] = '\0';
    return reverse_string(str);;
}