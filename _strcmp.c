/**
 * _strcmp - compares str
 * @s1: 1 par
 * @s2: 2 par
 * Return: l
 */
int _strcmp(char *s1, char *s2)
{
	int i, j, k, l;

	i = j = k = l = 0;

	while (*(s1 + i) != '\0')
		i++;

	while (*(s2 + j) != '\0')
		j++;

	while (k <= i && k <= j)
	{
		if (*(s1 + k) == *(s2 + k))
			l += 0;
		else
		{
			l = *(s1 + k) - *(s2 + k);
			break;
		}
		k++;
	}

	return (l);
}
