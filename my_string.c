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

char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
  
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
  
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
  
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
  
    str[i] = '\0'; // Append string terminator
    return reverse_string(str);;
}