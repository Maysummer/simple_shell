#include <stdio.h>
/**
 * comp - compares a char with chars in a dl
 * @dl: delimeter
 * @s: char to check for
 * Return: 1 or 0
 */
int comp(char s, const char *dl)
{
	while (*dl)
	{
		if (s == *dl)
			return (1);
		dl++;
	}
	return (0);
}
/**
 * _strtok - tokenizes a string using dl as delimeter
 * @s: string to tokenize
 * @dl: delimeter
 * Return: next token for each call
 */
char *_strtok(char *s, const char *dl)
{
	static char *t = "";
	char *save;
	int i = 0;


	if (s == NULL)
		s = t;

	save = s;

	while (s && *s)
	{
		if (comp(*s, dl))
		{
			while (comp(*s, dl) && *s)
			{
				*s = 0;
				s++;
			}
			t = s;
			if (*t == 0)
				t = NULL;
			save[i] = 0;
			return (save);
		}
		s++;
		i++;
	}
	t = NULL;
	return (save);
}
