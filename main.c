#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

char *program_name;

int main(int argc, char **argv)
{
    char *line = NULL, **args;
    int exit_status, status;
    (void)argc;
    program_name = argv[0];

    while (1)
    {
        print_prompt();
        if (prompt(&line) == -1)
            exit(0);

        args = split_line(line);
        if (args == NULL || args[0] == NULL)
        {
            free(line);
            continue;
        }

        free_args(args);
        free(line);
        line = NULL;
    }

    return 0;
}
