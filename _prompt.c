#include "main.h"
/**
 * _prompt - prints a prompt and gets line from stdin
 * @n: size of space to malloc for lineptr
 * @lineptr: where to save line
 *
 * Return: -1 or num of chars read
 */
ssize_t _prompt(size_t *n, char **lineptr)
{
	ssize_t k;

	_puts_no_newline("#cisfun$ ");
	k = _getline(lineptr, n, stdin);
	return (k);
}
