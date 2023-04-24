#include “main.h”

/**
 * _printf - Function that produces output according to a given format
 * @format: Output format
 *
 * Return: On success len.
*/

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
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				len += putchar(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				len += print_string(s);
			}
			else if (*format == '%')
			{
				len += _putchar('%');
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				len += print_intteger(num);
			}
		}
		else
		{
			len += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}
