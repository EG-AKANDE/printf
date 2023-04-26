#include "main.h"

/**
 * print_octal - Converts int argument to octal
 * @num: The the int to convert
 *
 * Return: On success len.
*/

int print_octal(unsigned int num)
{
	int len = 0;
	char buffer[20];/* Maximum number of digits for an unsigned int in octal*/
	int idx = 0;

	/* Convert num to string in octal format */
	do {

		buffer[idx++] = '0' + num % 8;
		num /= 8;
	} while (num > 0);
	/* Print the digits in reverse order to match the original number */
	for (int i = idx - 1; i >= 0; i--)
	{
		len += print_char(buffer[i]);
	}
	return (len);
}

/**
 * print_hexadecimal - Converts int argument to octal
 * @num: The the int to convert
 * @specifier: The specifier
 *
 * Return: On success len.
*/

int print_hexadecimal(unsigned int num, char specifier)
{
	int len = 0;
	char buffer[20];
	int idx = 0;

	/* Convert num to string in hexadecimal format */
	do {
		int digit = num % 16;

		if (digit < 10)
		{
			buffer[idx++] = '0' + digit;
		}
		else
		{
			if (specifier == 'x' || specifier == 'p')
			{
				buffer[idx++] = 'a' + (digit - 10);
			}
			else
			{
				buffer[idx++] = 'A' + (digit - 10);
			}
		}
		num /= 16;
	} while (num > 0);/* Print the digits in reverse order to match */
	for (int i = idx - 1; i >= 0; i--)
	{
		len += print_char(buffer[i]);
	}
	return (len);
}
