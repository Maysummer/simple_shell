#include "main.h"
/**
 * _setenv - sets an env variable
 * @name: new var name
 * @value: value of name
 * @overwrite: option to overwrite or not
 *
 * Return: -1 or 0;
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *check, *new_var, save_var_env[256];
	int i = 0, j = 0;
	extern char **environ;

	check = _getenv((char *)name);
	new_var = malloc((sizeof(char) * 256) + _strlen((char *)value));
	if (!new_var)
		return (-1);

	for (i = 0; name[i]; i++)
		new_var[i] = name[i];

	new_var[i++] = '=';

	for ( ; value[j]; i++, j++)
		new_var[i] = value[j];

	if (!check)
	{
		i = 0;
		while (environ[i])
			i++;
		environ[i] = new_var;
		environ[i + 1] = NULL;
	}
	else
	{
		if (!overwrite)
			return (0);
		else
		{
			i = 0;
			while (environ[i])
			{
				getvar(environ[i], save_var_env);
				if (!_strcmp(save_var_env, (char *)name))
				{
					environ[i] = new_var;
					break;
				}
				i++;
			}
		}
	}
	return (0);
}
