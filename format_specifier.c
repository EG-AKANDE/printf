#include "main.h"
int format_specifier(const char **format, va_list args)
{
	int len = 0;
	char specifier = *(*format);

	if (specifier == 'c')
	{
		char c = va_arg(args, int);

		len += print_char(c);
	}
	else if (specifier == 's')
	{
		char *s = va_arg(args, char *);

		len += print_string(s);
	}
	else if (specifier == '%')
	{
		len += print_char('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		len += print_integer(num);
	}
	else if (specifier == 'b')
	{
		unsigned int num = va_arg(args, unsigned int);

		len += print_binary(num);
	}
	else if (specifier == 'u')
	{
		unsigned int num = va_arg(args, unsigned int);

		len += print_unsigned_integer(num);
	}
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
