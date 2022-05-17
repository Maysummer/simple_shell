#include <stdlib.h>
/**
 * _strdup - copies a string literal an place in a new address
 * @str: string to copy
 *
 * Return: address of copied str
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0, j = 0;

	if (str == 0)
		return (0);

	while (*(str + i) != 0)
		i++;

	s = malloc((i + 1) * sizeof(char));

	if (s == 0)
		return (0);

	while (*(str + j) != 0)
	{
		s[j] = *(str + j);
		j++;
	}
	s[j] = '\0';

	return (s);
}

