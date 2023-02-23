#include "main.h"

/**
 * read_textfile - read from a text file or file
 * @filename: The name of the file to read from
 * Return: the extracted string
 */
char *read_textfile(const char *filename)
{
	char *line;
	FILE *fp;
	size_t bufsize;

	line = NULL;
	bufsize = 0;
	if (filename == NULL)
		fp = stdin;
	else
	{
		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
	}
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}


/*
 *{
 *	size_t buffersize;
 *	char *buffer;
 *	int fd;
 *	char c;
 *	FILE *fp;
 *	int pos;
 *
 *	pos = 0;
 *	buffer = malloc(sizeof(char) * MAX_BUFFER_INCR);
 *	buffersize = MAX_BUFFER_INCR;
 *	if (!buffer)
 *	{
 *		perror("Malloc");
 *		exit(EXIT_FAILURE);
 *	}
 *	if (filename == NULL)
 *		fd = 0;
 *	else
 *	{
 *		fp = fopen(filename, "r");
 *		if (fp == -1)
 *		{
 *			perror("fopen");
 *			exit(EXIT_FAILURE);
 *		}
 *		fd = fp
 *	}
 *	while (1)
 *	{
 *		read(fd, &c, 1);
 *		if (c == EOF || c == '\n')
 *		{
 *			buffer[pos] = '\0';
 *			return (buffer);
 *		}
 *		else
 *			buffer[pos] = c;
 *		pos++;
 *		if (pos >= buffersize)
 *		{
 *			buffersize += MAX_BUFFER_INCR;
 *			buffer = realloc(buffer, buffersize);
 *			if (!buffer)
 *			{
 *				perror("Realloc");
 *				exit(EXIT_FAILURE);
 *			}
 *		}
 *	}
 *}
**/
