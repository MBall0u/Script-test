#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *word[1], *sep = " ", *buf = NULL;
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
		word[0] = strtok(buf, sep);
			
		child_pid = fork();
		if (child_pid == 0)
			execve(word[0], word, NULL);
		wait(NULL);

		free(buf);
		buf = NULL;
	}
}
