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
 * print_string - Function to print a string to standard output
 * @s: The string to print
 *
 * Return: On success 1.
*/

int print_string(char *s)
{
	int len = 0; /* Initialize a counter for the number of characters written */
	while (*s) /* Loop through each character in the string until reaching the null terminator */
	{
			len += write(1, s, 1); /* Write the character at the current position to standard output and increment the counter */
			s++; /* Move to the next character in the string */
	}
	return len; /* Return the total number of characters written */
}
