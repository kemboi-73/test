#include "shell.h"

/**
 * isShellInteractive - Checks if the shell is interactive
 * @info: Pointer to the info_t struct
 * Return: 1 if shell is in interactive mode, 0 otherwise
 */

int isShellInteractive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * isDelimiter - Checks if a character is a delimiter
 * @c: The character to check
 * @delim: The string of delimiters
 * Return: 1 if the character is a delimiter, 0 otherwise
 */

int isDelimiter(char c, char *delim)
{
	while (*delim)
	{
	if (*delim++ == c)
	return (1);
	}
	return (0);
}
/**
 * isAlphabetic - Checks if a character is alphabeti
 * @c: The character to check
 * Return: 1 if the character is alphabetic, 0 otherwise
 */

int isAlphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);
	else
	return (0);
}
/**
 * convertStringToInt - Converts a string to an integer
 * @s: The string to be converted
 * Return: The converted integer value.
 */

int convertStringToInt(char *s)

{
	int i, sign = 1, flag = 0, result = 0;
	unsigned int output = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
		sign *= -1;

	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
	output *= 10;
	output += (s[i] - '0');
	}
else if (flag == 1)
	flag = 2;
	}
	if (sign == -1)
		result = -output;
	else
		result = output;
	return (result);
}
