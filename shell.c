#include "main.h"
/**
 * main - simple shell
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0
 */
int main(__attribute__((unused))int ac, char **av)
{
	pid_t cpid;
	char *p_argv[20], *lineptr = NULL, program[256];
	const char *dl = "	 ";
	int status, i = 0, j, k;
	size_t n = 10;
	extern char **environ;

	while (1)
	{
		/*if (_getenv("_"))
		_puts_no_newline("($) ");
		j = _getline(&lineptr, &n, stdin);*/
		j = _prompt(&n, &lineptr);
		if (j == EOF)
		{
			_puts("");
			break;
		}
		remove_new_line(lineptr);
		make_tok_array(lineptr, dl, p_argv);
		k = get_path_program(p_argv[0], program, environ);
		if (!_strcmp(program, "exit"))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

		if (!_strcmp(program, "/usr/bin/env"))
		{
			for(i = 0; environ[i]; i++)
				_puts(environ[i]);
			k = 2;
		}
		if (k == 1)
			cpid = fork();
		else
			cpid = 1;

		if (cpid == -1)
		{
			perror("Error");
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		if (cpid == 0)
		{
			execve(program, p_argv, NULL);
			perror(av[0]);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (!k)
				perror(av[0]);
			wait(&status);
		}
		i++;
	}
	free(lineptr);
	exit(EXIT_SUCCESS);
}
