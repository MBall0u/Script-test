#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *argv[] = {NULL, NULL}, *sep = "",*buf = NULL;
	size_t size = 64;
	ssize_t e_check;
	pid_t child_pid;

	while (1)
	{
		printf("$ ");
		e_check = getline(&buf, &size, stdin);
		if (e_check == -1)
		{
			printf("Something went wrong!\n");
			break;
		}
		
		argv[0] = strtok(buf, sep);
		printf("%s", argv[0]);

		child_pid = fork();
		if (child_pid == 0)
			execve(argv[0], argv, NULL);
		else
			wait(NULL);
		free(buf);
		buf = NULL;
	}
	return (0);
}
