#include <stdio.h>
#include <unistd.h>
int main(int ac, char **av)
{
	char *line = NULL;
	size_t linecap = 0;

	printf("$ ");
	getline(&line, &linecap, stdin);
}