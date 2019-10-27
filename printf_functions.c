#include <unistd.h>
#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - Function to print a single character to standard output
 *
 * @c: Parameter passed to function to process
 * Return: No return (Void function)
 */

void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * char_print - Function that prints a character to standard output
 *
 * @args: Variadic list of arguments
 * Return: The number of characters printed
 */

int char_print(va_list args)
{

	_putchar(va_arg(args, int));
	return (1);

}

/**
 * str_print - Function to print a string to standard output
 *
 * @args: Variadic list of arguments
 * Return: The number of characters printed
 */

int str_print(va_list args)
{
	int i, j;
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(NULL)";
	if (s[0] == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
		;
	for (j = 0; j < i; j++)
	{
		_putchar(s[j]);
	}
	return (i);
}

/**
 * int_print - Function that prints integers to standard output
 *
 * @args: Variadic list of arguments
 * Return: The number of characters printed
 */

int int_print(va_list args)
{

	long int num, div, i = 0;

	num = va_arg(args, int);

	if (num == 0)
	{
		_putchar('0');
		i = 1;
	}
	else if (num < 0)
	{
		_putchar('-');
		num = -num;
		i = 1;
	}
	if (num > 0)
	{
		for (div = 1; div <= num; div *= 10)
			;
		while (div > 1)
		{
			div /= 10;
			_putchar((num / div) + '0');
			num %= div;
			i++;
		}
	}
	return (i);

}

/**
 * uint_print - Function that print a unsigned int
 *
 * @args: Variadic list of arguments
 * Return: Count of arguments printed
 */

int uint_print(va_list args)
{

	unsigned int num, div, i = 0;

	num = va_arg(args, int);

	if (num == 0)
	{
		_putchar('0');
		i = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			_putchar((num / div) + '0');
			num %= div;
			div /= 10;
			i++;
		}
	}
	return (i);

}

int oct_print(va_list args)
{

	unsigned int num, i = 0, j = 0;
	int nums[100];

	num = va_arg(args, int);

	if (num < 9)
	{
		_putchar(num + '0');
		i = 1;
	}
	else if (num >= 9)
	{
		while (num > 0)
		{
			nums[j] = num % 8;
			num /= 8;
			j++;
		}
	}
	while (j--)
	{
		_putchar(nums[j] + '0');
		i++;
	}
	return (i);
}

/**
 * percent_print - Function that prints a "%" parameter passed into it
 *
 * @args: Variadic list of arguments
 * Return: The number of arguments printed
 */

int percent_print()
{
	_putchar('%');
	return (1);
}

/**
 * _convert - Function to convert integers according to its base
 *
 * @num: First parameter passed to function to process
 * @base: Second parameter passed to function to process
 * Return: A pointer to the converted number
 */

char *_convert(unsigned int num, int base)
{
	static char buff[33];
	char *ptr;

	ptr = &buff[sizeof(buff) - 1];
	*ptr = '\0';
	do
	{
		*--ptr = "0123456789abcdef"[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}
