#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LEN 1024
#define MAX_TOKENS 64
#define DELIMITER " \t\n"

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct
{
int readfd;

} info_t;
/**
 * struct list_s - Represents a node in a linked list.
 * struct - a short info about struct
 * @name: Pointer to the name string.
 * @value: Pointer to the value string.
 * @next: Pointer to the next node in the list.
 */
typedef struct list_s
{
char *name;
char *value;
struct list_s *next;
} list_t;
/*pro of exit.c*/
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
/*prototypes of env*/
char *_strtok(char *str, const char *delim);
int _strcmp(const char *s1, const char *s2);
/*ts*/
void free_all(char *buffer, char *p, char **arg);
void freearg(char **arg);


extern char **environ;


int env(char *trick, char *input);


char *build_path(char *dir, char *command);
char *find_command(char *command);

/*testing stuff*/
int is_command(char *filename);
char *create_path(char *dir, char *filename);
char *get_full_path(char *filename, list_t *path_list);
char *get_full_name(char *name, list_t *env_list);

char *read_cmd(void);
int execute_cmd(char *cmd);
void execute_child(char **input);
/*testing stuff*/
void print_prompt(void);
int prompt(char **line);
/*getline.c*/
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream);



char  **_tokenize(char *command, char *delim);
void ourexit(char *exit1, char **mpath, char **arr, char *args, int exit_stat);
size_t _strlen(char *s);
int print_string(char *str);
/*shell.c prototypes*/
int stat(const char *pathname, struct stat *statbuf);
int _putchar(char c);
int execmd(char **argv);

int main(int argc, char **argv);
char *get_location(char *cmd);

/*all prototypes of command_location.c*/
int isShellInteractive(info_t *info);
int isDelimiter(char c, char *delim);
int isAlphabetic(int c);
int convertStringToInt(char *s);

/*prototypes of shell_builtins.c*/
int builtin_exit(void);
int builtin_env(char **env);

/*proto of command_parser.c*/
char **parse_command(char *command);
void free_tokens(char **tokens);

/*prototype of cd_function.c*/
int cd(char *directory);

/* new */
#ifndef SHELL_H
#define SHELL_H
void print_prompt(void);
int prompt(char **line);
char **split_line(char *line);
int _atoi(char *str);
void free_args(char **args);
int execute(char **args);

#endif /* SHELL_H */


/* environ.c */
#endif
