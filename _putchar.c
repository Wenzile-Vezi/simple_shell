#include "main.h"

/**
 * _putchar - writes the character c to stdout.
 * @c: the character to print
 *
 * Return: 1 on success.
 * on error -1 is returned and erno is set appropriately
 */
int _putchar(char c)
{
	static int a;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE);
	{
		write(1, buff, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buff[++a] = c;
	return (a);
}	
