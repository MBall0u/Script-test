#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *argv[] = {NULL, NULL}, *sep = "\n",*buf = NULL;
	size_t size = 64;
	ssize_t e_check;
	pid_t cmd;
	int status;

	while ((e_check = getline(&buf, &size, stdin)) != -1)
	{
		printf("$ ");

		argv[0] = strtok(buf, sep);
		printf("%s", argv[0]);

		cmd = fork();
		if (cmd == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			waitpid(cmd, &status, 0);
		}
		free(buf);
		buf = NULL;
	}
	return (0);
}
