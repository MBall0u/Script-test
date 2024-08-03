#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *word, *sep = " ", *buf = NULL;
	size_t size = 64;
	ssize_t e_check;
	int count = 1;

	while (1)
	{
		printf("$ ");
		e_check = getline(&buf, &size, stdin);
		if (e_check == -1)
		{
			printf("Something went wrong!\n");
			break;
		}

		for (word = strtok(buf, sep); word; word = strtok(NULL, sep))
		{
			printf("Word #%d is %s\n", count, word);
			count++;
		}

		free(buf);
		buf = NULL;
	}
}
