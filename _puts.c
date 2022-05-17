#include "main.h"

/*
 * _puts- does put chars
 * @str: is arg
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
