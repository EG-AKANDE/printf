/**
 * print_binary - Converts int argument to binary
 * @int: The the int to convert
 *
 * Return: On success len.
*/

int print_binary(unsigned int num)
{
	int len = 0;
	char buffer[33]; /* Maximum number of bits for an unsigned int including null terminator */
	int idx = 0;

	/* Convert num to binary and store in buffer */
	do
	{
		buffer[idx++] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	while (num > 0);

	/* Print the binary representation in reverse order */
	while (idx > 0)
	{
		len += print_char(buffer[--idx]);
	}
	return len;
}
