#include "main.h"
/**
 * remove_new_line - changes the \n char in a getline returned string to
 * null char
 * @s: string to work on
 */
void remove_new_line(char *s)
{
	s[_strlen(s) - 1] = 0;
}
