#include "main.h"
/**
 * _getenv - mimics stdlib getenv
 * @s: name of var to get value
 * Return: pointer to variable
 */
char *_getenv(char *s)
{
	int i = 0, j = 0, k = 0;
	/*size_t k = 0;*/

	while (environ[i])
	{
		for (j = 0, k = 0; environ[i][j] && s[j]; j++, k++)
		{
			if (environ[i][j] != s[j])
				break;
		}
		if (k == _strlen(s) && environ[i][j] == '=')
			return (environ[i] + k + 1);
		i++;
	}

	return (NULL);
}
