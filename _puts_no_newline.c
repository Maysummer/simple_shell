#include "main.h"

/*
 * _puts_no_newline- does put chars
 * @str: is arg
 */
void _puts_no_newline(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
