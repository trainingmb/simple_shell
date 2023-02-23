#include "main.h"

/**
 * _putchar - writes a single character to standard output
 * @c: The character passed in to print
 * Return: Return output success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints string followed by newline
 * @str : String pointer
 */
void _puts(char *str)
{
	int siz = 0;

	while (str[siz] != '\0')
	{
		_putchar(str[siz++]);
	}
}

