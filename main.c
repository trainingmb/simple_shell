#include "main.h"
/**
 * main - main
 * Return: Return successful
 */
int main(void)
{
	char status;
	char *line;
	char **tokens;
	char *env[] = {NULL};

	status = 'c';
	status = status + 'c';
	while (1)
	{
		_puts("#cisfun$>");
		line = read_textfile(NULL);
		tokens = tokennize_line(line);
		execute(tokens, env);
		checkmalloc(tokens, -2);
	}

	return (EXIT_SUCCESS);
}
