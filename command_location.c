#include "shell.h"

/**
 * get_location -gegts the path to the command passed as argument
 * @cmd:command whose location is required
 * Return: command path, then NULL if no patch is found
 */

char *get_location(char *cmd)

{
char *path, *copy_path, *path_tkn, *file_path;
int cmd_len, dir_len;

path = getenv("PATH");
if (path)
{
	copy_path = strdup(path);
	cmd_len = strlen(cmd);
	path_tkn = strtok(copy_path, ":");
	while (path_tkn != NULL)
	{
		dir_len = strlen(path_tkn);
		file_path = malloc(cmd_len + dir_len + 2);
		sprintf(file_path, "%s/%s", path_tkn, cmd);
		if (access(file_path, F_OK) == 0)
		{
			free(copy_path);
			free(file_path);
			return (file_path);
		}
		else
		{
			free(file_path);
			free(copy_path);
			path_tkn = strtok(NULL, ":");
		}
	}
	free(copy_path);
	if (access(cmd, F_OK) == 0)
	{
		return (cmd);
	}
}
return (NULL);
}
