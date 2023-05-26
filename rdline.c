#include "shell.h"

/**
 * read_cmd - Reads a command from standard input..
 *
 * Return: return the number of characters read, or -1 otherwise
 */
char *read_cmd(void)
{
	ssize_t bytes;
	char *cmd = NULL;
	size_t len = 0;

	bytes = getline(&cmd, &len, stdin);
	if (bytes == -1)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	return (cmd);
}
