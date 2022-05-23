#include "main.h"

/**
 * start_storage - function to start the stocker
 * @stocker: buffer
 * @format: string to print
 * @params: params for the string
 * Return: stocker with the full string
 */

char *start_storage(char *stocker, const char *format, va_list params)
{
	int i, sp;

	stocker[0] = '\0';

	for (i = 0, sp = 0; format[i] != '\0'; i++, sp++)
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (NULL);
		}
		else if (format[i] == '%')
		{
			validate_option(stocker, format[i + 1], params);
			sp = _strlen(stocker) - 1;
			i++;
		}
		else
		{
			stocker[sp] = format[i];
			stocker[sp + 1] = '\0';
		}
	}
	return (stocker);
}

/**
 * validate_option - function to validate the type of function to use
 * @stocker: buffer
 * @format: string to print
 * @params: params for the string
 * Return: stocker with the full string
 */

char *validate_option(char *stocker, char format, va_list params)
{
	char warning[3];

	forms formlist[] = {
		{"s", printstr},
		{"c", printchar},
		{"i", printint},
		{"d", printint},
		{"x", printhex},
		{NULL, NULL}
	};
	int i;

	warning[0] = '%';
	warning[1] = format;
	warning[2] = '\0';
	for (i = 0; formlist[i].f; i++)
	{
		if (format == *formlist[i].f)
		{
			formlist[i].print_str(params, stocker);
			i++;
			break;
		}
		else if (format == '%')
		{
			printper(stocker);
			i++;
			break;
		}
	}
	if (*formlist[i - 1].f != format && format != '%')
	{
		_strncat(stocker, warning, 3);
		return (stocker);
	}
	return (stocker);
}
