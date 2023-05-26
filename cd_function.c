#include "shell.h"

/**
 * cd - Change the current working directory.
 * @directory: The directory to change to
 * Return: On success, returns 0. On failure, returns 1
 */
int cd(char *directory)
{
	char *cwd = getcwd(NULL, 0);
	int rc;

	if (directory == NULL)
	{
		directory = getenv("HOME");
		if (directory == NULL)
		{
			perror("cd: unable to determine home directory");
			return (1);
		}
	}

	rc = chdir(directory);
	{
		if (rc != 0)
		{
			perror("cd: cannot change directory");
			return (1);
		}
	if (cwd == NULL)
	{
		perror("cd: cannot get current working directory");
		return (1);
	}
if (setenv("PWD", cwd, 1) != 0)
{
	perror("cd: failed to set PWD environment variable");
	return (1);
}
	free(cwd);
	return (0);
}
}

