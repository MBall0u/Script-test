#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *sep = "\n ", *word, *str;
	size_t size = 64;
	pid_t cmd;
	int status, count;
	ssize_t check;
	char **args;
	char *buf = NULL;

	while (1)
	{
		printf("$ ");

		count = 0;
		check = getline(&buf, &size, stdin);
		if (check == -1)
		{
			printf("Something went wrong!\n");
			break;
		}
		str = malloc(sizeof(char) * (strlen(buf) + 1));
		if (!str)
		{
			perror("Error");
			return (1);
		}
		strcpy(str, buf);

		for (word = strtok(str, sep); word != NULL; word = strtok(NULL, sep))
		{
			count++;
		}

		args = malloc(sizeof(char *) * count);
		if (!args)
		{
			perror("Error");
			return (1);
		}

		count = 0;
		for (word = strtok(str, sep); word != NULL; word = strtok(NULL, sep))
		{
			args[count] = word;
			count++;
		}

		cmd = fork();
		if (cmd == 0)
		{
			check = execve(args[0], args, NULL);
			if (check == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			check = waitpid(cmd, &status, 0);
			if (check == -1)
			{
				perror("Error");
				return (1);
			}
		}
		free(str);
		str = NULL;

		free(args);
		args = NULL;
	}
	return (0);
}
