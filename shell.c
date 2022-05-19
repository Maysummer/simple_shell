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
	char *p_argv[20], lineptr[1024] = {0}, program[256];
	const char *dl = "	 ";
	int status, i = 0, j = 0, k = 0;
	size_t n = 10;
	extern char **environ;

	while (1)
	{
		for (i = 0; i < 120; i++)
			lineptr[i] = 0;
		if (isatty(0))
			_puts_no_newline("#cisfun$ ");

		j = _getline(lineptr, &n, stdin);
		if (j == EOF)
		{
			/*if (lineptr)
				free(lineptr);*/
			if(isatty(0))
				_puts("");
			break;
		}
		remove_new_line(lineptr);
		make_tok_array(lineptr, dl, p_argv);
		k = get_path_program(p_argv[0], program, environ);
		if (!_strcmp(program, "exit"))
		{
			if (p_argv[1])
				exit(atoi(p_argv[1]));
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
			/*free(lineptr);*/
			perror("Error");
			exit(EXIT_FAILURE);
		}

		if (cpid == 0)
		{
			execve(program, p_argv, NULL);
			/*free(lineptr);*/
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (!k)
			{
				perror(av[0]);
			}
			/*free(lineptr);*/
			wait(&status);
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}
