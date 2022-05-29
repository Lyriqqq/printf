#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
* _printf - function that print characters for conditional character
* @format: char pointer
*
* Return: integer equal to lenght the print
*/


int _printf(const char *format, ...)
{
	va_list pa;
	const char *p;
	int num = 0;

	if (format == NULL)
		return (-1);

	va_start(pa, format);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			switch (*++p)
			{
				case 's':
					num = num + print_string(pa);
					break;
				case 'c':
					num = num + print_character(pa);
					break;
				case '%':
					num = num + 1;
					_putchar('%');
					break;
				case '\0':
					return (-1);
				case 'i':
				case 'd':
					num = num + print_integer(pa);
					break;
				default:
					_putchar('%'), _putchar(*p), num = num + 2;
			}
		}
		else
			_putchar(*p), num++;
	}
	va_end(pa);
	return (num);
}
