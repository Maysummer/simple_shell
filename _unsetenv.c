#include "main.h"
/**
 * _unsetenv - unsets an environment variable
 * @name: name of var to unset
 *
 * Return: 0 or -1
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	char *check, save[256];
	int i = 0, j = 0;

	check = _getenv((char *)name);

	if (!check)
		return (0);

	while (environ[i])
	{
		getvar(environ[i], save);
		if (!_strcmp(save, (char *)name))
		{
			for ( ; environ[i]; i++)
			{
				environ[i] = environ[i + 1];
			}
			j = 1;
			environ[i] = NULL;
		}
		if (j == 1)
			break;
		i++;
	}
	return (0);
}
