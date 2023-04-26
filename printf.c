#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Function that produces output according to a given format
 * @format: Output format
 * Return: On success, the number of characters printed.
 */

/* Defining the function _printf and its parameters */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
            {
                break;
            }
            if (*format == '%')
            {
                len += print_char('%');
            }
            else if (*format == 'c' || *format == 's' || *format == 'd' || *format == 'i' || *format == 'u')
            {
                len += handle_format_specifier(&format, args);
            }
            else if (*format == 'o' || *format == 'x' || *format == 'X')
            {
                len += handle_format_specifier1(&format, args);
            }
            else
            {
                len += print_char('%');
                len += print_char(*format);
            }
        }
        else
        {
            len += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return len;
}
