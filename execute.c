#include "main.h"

/**
 * execute - Execute a list of commands
 * @argv: List of arguments
 * @env: Env list;
 * Return: 1 if success
 */
int execute(char **argv, char **env)
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid == 0)
	{
		printf("\n'%s'\n", argv[0]);
		if (execve(argv[0], argv, env) == -1)
		{
			perror(argv[0]);
		}
		checkmalloc(argv, -2);
		exit(EXIT_FAILURE);
	}
	else if (childpid < 0)
	{
		perror("Fork");
	}
	else
	{
		do
			waitpid(childpid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * getsscount - Count the number of whitespace seperated
 * strings
 * @line: the string to be manipilated
 * Return: The count of substring
 **/
int getsscount(char *line)
{
	int i, count;
	char ws;

	count = 0;
	ws = 1;
	for (i = 0; line[i] != '\0'; i++)
	{
		if (ws == 0)
		{
			if (line[i] == ' ')
				ws = 1;
		}
		else
		{
			if (line[i] != ' ')
			{
				ws = 0;
				count++;
			}
		}
	}
	return (count);
}

/**
 * tokennize_line - change a
 * line into a list of commands
 * @line: Line to tokennize
 * Return: List of token strings
 **/
char **tokennize_line(char *line)
{
	char **tokens;
	int i, subslen, count;
	char ws;

	ws = 0;
	count = getsscount(line);
	tokens = (char **) malloc((count + 1) * sizeof(char *));
	checkmalloc(tokens, -1);
	tokens[count] = NULL;
	count = ws = 0;
	subslen = 0;
	for (i = 0; line[i] != '\0'; i++)
	{
		if (ws == 0)
		{
			if (line[i] == ' ')
			{
				ws = 1;
				tokens[count] = genstring(line, i - subslen, subslen);
				checkmalloc(tokens, count);
				count++;
			}
			else
				subslen += 1;
		}
		else
		{
			if (line[i] != ' ')
			{
				ws = 0;
				subslen = 1;
			}
		}
	}
	if (ws == 0)
		tokens[count] = genstring(line, i - subslen, subslen);
	return (tokens);
}

/**
 * genstring - Generate a malloc string
 * @str: Pointer to a string
 * @startpos: First position
 * @len: The len of the substring
 * Return: A Malloced generated substring
 **/
char *genstring(char *str, int startpos, int len)
{
	char *substr;
	int i;

	substr = (char *) malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (substr);
	for (i = 0; i < len; ++i)
	{
		substr[i] = str[i + startpos];
		if (substr[i] == '\n')
			substr[i] = ' ';
	}
	substr[len] = '\0';
	return (substr);
}
/**
 * checkmalloc - Check if allocation was correct
 * @created: Created Nul terminated array of strings
 * @pos: Position indicator in string
 **/
void checkmalloc(char **created, int pos)
{
	size_t i;

	if (created == NULL)
		exit(EXIT_FAILURE);
	if (pos != -1)
	{
		if (pos == -2)
		{
			for (i = 0; created[i] != NULL; i++)
			{
				free(created[i]);
			}
			free(created);
		}
		else if (created[pos] == NULL)
		{
			for (i = 0; created[i] != NULL; i++)
			{
				free(created[i]);
			}
			free(created);
			exit(EXIT_FAILURE);
		}

	}
}
