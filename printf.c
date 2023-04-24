#include "main.h"

/**
 * _printf - Function that produces output according to a given format
 * @format: Output format
 * Return: On success, the number of characters printed.
 */

/* Defining the function _printf and its parameters */
int _printf(const char *format, ...)
{
/* Initializing variables */
int len = 0;
va_list args;

/* Starting the list of arguments */
va_start(args, format);

/* Looping through the format string */
while (*format)
{
	/* Checking if the current character is a format specifier */
	if (*format == '%')
	{
		format++;
		/* Adding the length returned by handle_format_specifier to len */
		len += handle_format_specifier(&format, args);
	}
	/* If the current character is not a format specifier */
	else
	{
		/* Printing the character and adding 1 to len */
		len += print_char(*format);
		/* Moving to the next character in the format string */
		format++;
	}
}

/* Ending the list of arguments */
va_end(args);
/* Returning the number of characters printed */
return (len);
}
