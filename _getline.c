#include "main.h"
/**
 * _getline - mimics getline func
 * @lineptr: buff to save line
 * @n: size to allocate
 * @stream: file to read from
 * Return: number of bytes read'
 */
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t rd = 1, i = 0, j = 0, k = 0;
	char *buff;

	if (*n != 0)
	{
		buff = malloc(*n);
		*lineptr = malloc(*n);
	}
	else
	{
		buff = malloc(120);
		*lineptr = malloc(120);
		*n = 120;
	}

	if (!*lineptr || !buff)
		return (-2);

	while (1)
	{
		rd = fread(buff + i, 1, 1, stream);
		i++;
		k += rd;
		while (j < k)
		{
			(*lineptr)[j] = buff[j];

			if ((*lineptr)[j] == '\n')
			{
				free(buff);
				return (j + 1);
			}
			j++;
		}
		if (k == *n)
		{
			buff = realloc(buff, *n + 120);
			*lineptr = realloc(buff, *n + 120);
			if (!buff || !*lineptr)
			{
				free(buff);
				return (-3);
			}
			*n = *n + 120;
		}
		if (feof(stream))
			break;
	}
	free(buff);
	return (-1);
}
