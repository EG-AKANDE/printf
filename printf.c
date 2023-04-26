#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Function that produces output according to a given format
 * @format: Output format
 * Return: On success, the number of characters printed.
 */

/* Defining the function _printf and its parameters */
int _printf(const char *format, ...) /* Defining _printf and parameters */
{
int len = 0; /* Initializing length variable */

va_list args; /* Declaring a variable of type va_list */

va_start(args, format); /* Initializing the va_list variable for first arg */

while (*format) /* Looping through format str until str end */
{
	if (*format == '%') /* If char is percent sign, handle specifier */
{
	format++; /* Move format pointer to next char */

	if (*format == '\0')  /* If format specifier at end, exit loop */
{
	break;
}

	if (*format == '%') /* If fmt specifier percent sign, print percent */
{
	len += _putchar('%'); /* sign and increment length counter */
}
	else if (*format == 'c' || *format == 's' || *format == 'd' ||
	*format == 'i' || *format == 'u') /* uns int, handle */
{
	len += handle_format_specifier(&format, args);
	}
	else if (*format == 'o' || *format == 'x' || *format == 'X')
{
	len += handle_format_specifier1(&format, args);
}
	else
{
	len += _putchar('%'); /* If invalid, print percent sign */
	len += _putchar(*format);
}
}
	else
{
	len += _putchar(*format); /* If char not percent, print char */
}

	format++; /* Move fmtt pntr to next character */
}

	va_end(args); /* Clean up the va_list variable */

	return (len); /* Return the total length of the output */
}
