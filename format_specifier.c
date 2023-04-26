#include "main.h"

/**
 * format_specifier - processes a single format specifier
 * @format: pntr to present position
 * @args: the the va_list of args
 * Return: output length
 */

int format_specifier(const char **format, va_list args)
{
	int len = 0; /* Initialize */
	char specifier = *(*format); /* Get the specifier character */

	if (specifier == 'c') /* If the specifier is for a character */
	{
		char c = va_arg(args, int); /* Get the corresponding argument */

		len += _putchar(c); /* Call the function to print the character */
	}
	else if (specifier == 's') /* If the specifier is for a string */
	{
		char *s = va_arg(args, char *); /* Get the matching arg from va_list */

		len += print_string(s); /* Call the function to print the string */
	}
	else if (specifier == '%') /* If the specifier is for a percent sign */
	{
		len += _putchar('%'); /* Call the function to print the sign */
	}
	else if (specifier == 'd' || specifier == 'i') /* If for dec or int */
	{
	int num = va_arg(args, int); /* Get matching arg from va_list */

		len += print_integer(num); /* Call the function to print int */
	}
	else if (specifier == 'b') /* If specifier is for a binary */
	{
		unsigned int num = va_arg(args, unsigned int); /* Get matching arg */

		len += print_binary(num); /* Call function to print binary */
	}
	else if (specifier == 'u')
	{
		unsigned int num = va_arg(args, unsigned int);

		len += print_unsigned_integer(num);
	}
	(*format)++; /* Move the format pointer to the next char in input str */
	return (len); /* Return the total length of the printed output */
}

/**
 * format_specifier1 - processes a single format specifier
 * @format: pntr to present position
 * @args: the the va_list of args
 * Return: output length
 */


int format_specifier1(const char **format, va_list args)
{
	int len = 0;
	char specifier = *(*format);

	else if (specifier == 'o')
	{
		unsigned int num = va_arg(args, unsigned int);

		len += print_octal(num);
	}
	else if (specifier == 'x' || specifier == 'X')
	{
		unsigned int num = va_arg(args, unsigned int);

		len += print_hexadecimal(num, specifier);
	}
	(*format)++;
	return (len);
}
