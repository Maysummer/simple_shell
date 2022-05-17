#include "main.h"

/**
 * _strlen - returns lentgh of sting
 * @s: par str
 * Return: i after loop
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
