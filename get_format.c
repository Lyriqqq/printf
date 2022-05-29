#include "main.h"

/**
 * get_format - Select the function according to the placeholder
 * @fmt: Pointer to the placeholder
 *
 * Return: 0 on success
 */

int (*get_format(char fmt))()
{
	print_f opt[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_num},
		{"d", print_dec},
		{NULL, NULL}
	};

	int posit_opt = 0;

	while (opt[posit_opt].placeholder)
	{
		if (opt[posit_opt].placeholder[0] == fmt)
			return (opt[posit_opt].f);
		posit_opt++;
	}
	return (NULL);
}
