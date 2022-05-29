#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to character string
 *
 * Return: number of character printed excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list list;
	int (*g_fmt)();
	int posit_fmt, len_fmt = 0;

	if ((!format) || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);

	for (posit_fmt = 0; format[posit_fmt] && format; posit_fmt++)
	{
		if (format[posit_fmt] == '%')
		{
			if (format[posit_fmt + 1] != '%')
			{
				g_fmt = get_format(format[posit_fmt + 1]);

				if (g_fmt)
					len_fmt += g_fmt(list), posit_fmt++;
				else
					write(1, &format[posit_fmt], 1), len_fmt++;
			}
			else
				write(1, &format[posit_fmt], 1), len_fmt++, posit_fmt++;
		}
		else
			write(1, &format[posit_fmt], 1), len_fmt++;
	}
	va_end(list);
	return (len_fmt);
}}
