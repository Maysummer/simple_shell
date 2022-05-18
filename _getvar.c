#include "main.h"
/**
 * getvar - gets the variable name of an env variable
 * @s: var=value
 * @save: save the name here
 *
 * Return: 0;
 */
int getvar(char *s, char *save)
{
	int i = 0;

	while (save[i])
	{
		save[i] = 0;
		i++;
	}

	for (i = 0; s[i] != '='; i++)
		save[i] = s[i];
	save[i] = 0;

	return (0);
}

