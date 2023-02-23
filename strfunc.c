#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s : String pointer
 *
 * Return: Returns the length of the array
 */
int _strlen(char *s)
{
	int siz = 0;

	while (s[siz] != '\0')
	{
		siz++;
	}
	return (siz);
}
