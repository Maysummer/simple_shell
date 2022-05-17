#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * make_tok_array - makes an array strings from a line of string
 * @s: line of string
 * @dl: delimeter
 * @arr: array to save string
 * Return: 1 or 0
 */
int make_tok_array(char *s, const char *dl, char *arr[])
{
	char *token = _strtok(s, dl);
	int i = 0;

	while (token)
	{
		arr[i] = token;
		token = _strtok(NULL, dl);
		i++;
	}
	arr[i] = NULL;

	return (1);
}
