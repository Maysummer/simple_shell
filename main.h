#ifndef HEADER
#define HEADER

/**
 * struct PATH_list - a linked list of each directory of PATH
 * @p_dir: each directory name
 * @next: next node
 */
typedef struct PATH_list
{
	char *p_dir;
	struct PATH_list *next;
} path_l;

#include <stdio.h>
#include <stdlib.h>
/*#include <string.h>*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
ssize_t _prompt(size_t *n, char **lineptr);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void _puts_no_newline(char *str);
int _strlen(char *s);
char *_strdup(char *str);
int make_list_version2(path_l **head, char *p_dir[]);
int make_list(path_l **head, char *p_dir);
size_t _getline(char *lineptr, size_t *n, FILE *stream);
int make_tok_array(char *s, const char *dl, char *arr[]);
char *_strtok(char *s, const char *dl);
void remove_new_line(char *s);
int get_program(char *short_prog, char *full_prog, char **en);
int get_path_program(char *short_prog, char *full_prog, char **en);
char *_getenv(char *s);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int getvar(char *s, char* save);

#endif
