#include "main.h"

/**
 * printstr - Function that prints a string
 * @params: Arguments passed in the elypsis
 * @stocker: Buffer
 * Return: buffer with the new string
 */

char *printstr(va_list params, char *stocker)
{
	char *str;
	int len;
	char warning[7] = {'(', 'n', 'u', 'l', 'l', ')', '\0'};

	if (params)
	{
		str = va_arg(params, char *);
		if (str != NULL)
		{
			len =  _strlen(str);
			_strncat(stocker, str, len);
		}
		else
			_strncat(stocker, warning, 7);
	}
	return (stocker);
}

/**
 * printchar - Function that prints a char
 * @params: Arguments passed in the elypsis
 * @stocker: buffer
 * Return: stocker with the char
 */

char *printchar(va_list params, char *stocker)
{
	char chr;
	char warning[1] = {'\0'};

	if (params)
	{
		chr = va_arg(params, int);
		if (chr)
		{
		_strncat(stocker, &chr, 1);
		}
		else
			_strncat(stocker, warning, 2);
	}
	return (stocker);
}

/**
 * printper - function that prints a %
 * @stocker: buffer
 * Return: Buffer with the %
 */

char *printper(char *stocker)
{
	int len;

	len = _strlen(stocker);
	stocker[len] = '%';
	stocker[len + 1] = '\0';
	return (stocker);
}
