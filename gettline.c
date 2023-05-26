#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * mygetline - reads a line from STDIN
 * @lineptr: pointer to pointer to storage buffer
 * @n: pointer to size of buffer
 * @stream: file to read line from
 *
 * Return: number of characters read, or -1 on failure
 */
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL;
	ssize_t bytes_read;
	size_t line_size = 0;
	char *new_line;

	if (*lineptr == NULL || *n == 0) {
		/* If the buffer or its size is not provided, allocate a new one */
		line = malloc(BUFFER_SIZE);
		if (line == NULL) {
			return -1;
		}
		*n = BUFFER_SIZE;
	} else {
		/* Reuse the existing buffer */
		line = *lineptr;
	}

	while ((bytes_read = getc(stream)) != EOF) {
		if (bytes_read == '\n') {
			break;
		}

		if (line_size == *n - 1) {
			/* Increase the buffer size if it's full */
			*n *= 2;
			new_line = realloc(line, *n);
			if (new_line == NULL) {
				free(line);
				return -1;
			}
			line = new_line;
		}

		line[line_size++] = bytes_read;
	}

	if (bytes_read == EOF && line_size == 0) {
		/* Return -1 if no characters were read before encountering EOF */
		free(line);
		return -1;
	}

	line[line_size] = '\0';  /* Add null terminator */

	*lineptr = line;

	return line_size;
}
