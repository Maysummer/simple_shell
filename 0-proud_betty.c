#include <stdio.h>
#include <unistd.h>

/**
 * main - just trying to make betty proud
 *
 * Return: 0
 */
int main(void)
{
	pid_t mypid;

	mypid = getpid();
	printf("%u\n", mypid);
	return (0);
}
