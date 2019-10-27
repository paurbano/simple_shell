#include "holberton.h"
#include <stdlib.h>

/**
 *
 *
 *
 *
 *
 */

int _printf(const char *format, ...)
{

	va_list args;
	int counter = 0, i, j;
	op_print op[] = {
		{"c", char_print},
		{"s", str_print},
		{"%", percent_print},
		{"i", int_print},
		{"d", int_print},
		{"u", uint_print},
		{"o", oct_print},
		{NULL, NULL}
	};

	va_start(args, format);
	if (format == NULL)
		return (0);
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			_putchar(format[i]);
			counter++;
			i++;
		}
		if (format[i] != '\0')
		{
			i++;
		}
		else
			break;
		for (j = 0; j < 9; j++)
		{
			if (format[i] == *(op[j]).format)
			{
				counter += op[j].function(args);
				break;
			}
		}
	}
	va_end(args);
	return (counter);

}
