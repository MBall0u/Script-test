#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *s, *sep = "\n ", *buf, *word;
	size_t size = 64;
	pid_t cmd;
	int status, count = 0;
	ssize_t check;
	char **args;

	buf = malloc(size);
	if (!buf)
	{
		perror(s);
		return (1);
	}
	args = malloc(sizeof(char *) * size);
	if (!args)
	{
		perror(s);
		return (1);
	}

	while ((check = getline(&buf, &size, stdin)) != -1)
	{
		printf("$ ");

		for (word = strtok(buf, sep); word != NULL; word = strtok(NULL, sep))

		cmd = fork();
		if (cmd == 0)
		{
			execve(args[0], args, NULL);
		}
		else
		{
			waitpid(cmd, &status, 0);
		}
	}
	free(buf);
	free(args);
	buf = NULL;
	return (0);
}
