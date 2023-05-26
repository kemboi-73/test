#include "shell.h"

/**
 * freearg - function that frees the memory allocated for an array of strings
 * @arg: array of pointers to character
 */
void freearg(char **arg)
{
	int i;

	for (i = 0; arg[i] != NULL; i++)
		free(arg[i]);

	free(arg);
}

/**
 * free_all - function that frees all allocated memory
 * @buffer: buffer where getline stores the commands
 * @p: pointer to character
 * @arg: array of pointers to character
 */
void free_all(char *buffer, char *p, char **arg)
{
	free(buffer);
	free(p);
	freearg(arg);
}
