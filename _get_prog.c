#include "main.h"
/**
 * which - checks if a file exist in the PATH
 * @short_prog: program passed to terminal
 * @full_prog: full path to program
 * @en: environment variables string
 * Return: -1 or 0;
 */
int get_program(char *short_prog, char *full_prog, char **en)
{
	int i = 0, j = 0, k = 0, l;
	char *path;
	struct stat st;

	full_prog[0] = 0;
	while(en[i])
	{
		if (en[i][j] == 'P' && en[i][j + 1] == 'A'
		   && en[i][j + 2] == 'T' && en[i][j + 3] == 'H')
		{
			path = _strdup(en[i]);
			break;
		}
		i++;
	}

	i = 4;
	while (path[i])
	{
		if (path[i] == '/' && (path[i - 1] == ':' || path[i - 1] == '='))
		{
			for (j = 0; full_prog[j]; j++)
				full_prog[j] = 0;
			l = i;
			j = 0;
			k = 0;
			while (path[l] != 0 && path[l] != ':')
			{
				if (short_prog[j] != path[l])
					k += 1;
				full_prog[j] = path[l];
				j++;
				l++;
			}
			if (k == 0)
			{
				if (stat(short_prog, &st) == 0)
				{
					for(j = 0; full_prog[j]; j++)
						full_prog[j] = 0;
					for(k = 0; short_prog[k]; k++)
						full_prog[k] = short_prog[k];
					full_prog[k] = 0;
					if ((st.st_mode & S_IFMT) != S_IFDIR)
						return (1);
					else
					{
						full_prog[0] = 0;
						return 0;
					}
				}
			}
			else
			{
				if(*short_prog == '/' || *short_prog == '.')
				{
					for (j = 0; short_prog[j]; j++)
						full_prog[j] = short_prog[j];
					full_prog[j] = 0;
					return (0);	
				}	
			}
			k = 0;
			full_prog[j] = '/';
			j++;
			while (short_prog[k])
			{
				full_prog[j] = short_prog[k];
				k++;
				j++;
			}
			full_prog[j] = 0;
		}
		if (stat(full_prog, &st) == 0)
		{
			if ((st.st_mode & S_IFMT) != S_IFDIR)
				return (1);
			break;
		}
		i++;
	}
	for (j = 0; short_prog[j]; j++)
		full_prog[j] = short_prog[j];
	full_prog[j] = 0;
	return (0);
}
