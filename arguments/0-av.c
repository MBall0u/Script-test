#include <stdio.h>
#include <unistd.h>
int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("Argument #%d is %s", (i+1), av[i]);
		i++;
	}
	return (0);
}
