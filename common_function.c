#include "main.h"

/**
 * _strncat - concatenates two strings
 * @src: First string to append
 * @dest: Second string to append
 * @n: number of bytes
 * Return: Pointer to the resulting string
 **/

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	for (j = 0; j < n; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * my_reverse - function to reverse a string
 * @str: new string
 * @len: size of the integer
 */

void my_reverse(char str[], int len)
{
	int start, end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

/**
 * my_itoa - function to convert from integer to string
 * @num: the number to convert
 * @str: new string
 * @base: the base of the conversion
 * Return: string with the integer
 */


char *my_itoa(int num, char *str, int base)
{
	int i = 0;
	int isNegative = 0;

	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}

	if (num < 0 && base == 10)
	{
		isNegative = 1;
		/*num = num * -1;*/
	}

	while (num != 0)
	{
		int rem = num % base;
		if (isNegative)
			rem  *= -1;
		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	my_reverse(str, i);

	return (str);
}

/**
* _strlen - function that returns the length of a string.
* @s: string
* Return: length of string
**/

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
