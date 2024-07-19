#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *buf = NULL;
	size_t size = 64;
	ssize_t e_check;
	pid_t child_pid;

	while (1)
	{
		printf("$ ");
		e_check = getline(&buf, &size, stdin);
		if (e_check == -1)
			break;
		child_pid = fork();
		if (child_pid == 0)
			execve(buf, NULL, NULL);
		wait(NULL);

		free(buf);
		buf = NULL;
	}
}
