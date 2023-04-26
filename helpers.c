#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string to stdout
 * @s: The string to print
 *
 * Return: The number of characters printed.
 */
int print_string(char *s)
{
	int len = 0; /* counter for the number of characters printed */

	while (*s)
	{
		len += write(1, s, 1); /* Write the current character */
		s++; /* Move to the next character in the string */
	}

	return (len); /* Return the total number of characters printed */
}

/**
 * print_integer - prints an integer to stdout
 * @num: The integer to print
 *
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
	int len = 0; /* counter for the number of characters printed */
	char buffer[12]; /* buffer for max len of int plus sign and null termin */
	int idx = 0; /* index variable for buffer */
	int is_negative = 0; /* flag to indicate if the integer is negative */

	if (num == 0)
	{
		return (_putchar('0')); /* If int = 0, print '0', return num of chars */
	}

	if (num < 0)
	{
		is_negative = 1; /* If the integer is negative, set the flag */
		num = -num; /* Convert the integer to its absolute value */
	}

	/* Convert int to str in reverse, store in buffer */
	while (num > 0)
	{
		buffer[idx++] = num % 10 + '0'; /* Convert dig to ASCII, store in buffer */
		num /= 10; /* Remove the last digit from the integer */
	}

	if (is_negative)
	{
		buffer[idx++] = '-'; /* If int was -ve, add '-' to buffer */
	}

	/* Print chars in buffer in reverse to stnd, increment counter */
	while (idx > 0)
	{
		len += _putchar(buffer[--idx]);
	}

	return (len); /* Return the total number of characters printed */
}

/**
 * print_binary - Converts int argument to binary
 * @num: The the int to convert
 *
 * Return: On success len.
*/

int print_binary(unsigned int num)
{
	int len = 0;

	/* Maximum number of bits for an unsigned int including null terminator */
	char buffer[33];
	int idx = 0;

	/* Convert num to binary and store in buffer */
	do {
		buffer[idx++] = (num & 1) ? '1' : '0';
		num >>= 1;
	} while (num > 0);
	/* Print the binary representation in reverse order */
	while (idx > 0)
	{
		len += _putchar(buffer[--idx]);
	}
	return (len);
}

/**
 * print_unsigned_integer - converts it to a string in decimal format using
 * @num: The the int to convert
 *
 * Return: On success len.
*/

int print_unsigned_integer(unsigned int num)
{
	int i;
	int len = 0;
	char buffer[20];
	int idx = 0;

	/* Convert num to string in decimal format */
	do {
		buffer[idx++] = '0' + num % 10;
		num /= 10;
	} while (num > 0);
	/* Print the digits in reverse order to match the original number */
	for (i = idx - 1; i >= 0; i--)
	{
		len += _putchar(buffer[i]);
	}
	return (len);
}
