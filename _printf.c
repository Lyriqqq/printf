#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
* _printf - function like printf.
* @format: format to print.
* Return: lenght.
*/
int _printf(const char *format, ...)
{
	int i = 0, leng = 0, count = 0;
	va_list args;
	char *str;

	va_start(args, format);
	if (!format || (*format == '%' && strlen(format) == 1))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i - 1] != '%' && format[i] != '%')
			putchar(format[i]);
		else if (format[i - 1] == '%')
		{	count = count + 2;
			switch (format[i])
			{   case 'c':
					leng++;
					putchar((char)va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					leng += _put(str);
					break;
				case 'i':
				case 'd':
					leng += print_number(va_arg(args, int));
					break;
				case 'b':
					leng += _bin(va_arg(args, int));
					break;
				default:
					leng +=	_other_print(format[i], format[i - 1], format[i + 1]);
					break;
			}
		}
		i++;
	}
	va_end(args);
	return (i + leng - count);
}
