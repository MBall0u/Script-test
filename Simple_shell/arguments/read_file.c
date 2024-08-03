#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *buf = NULL;
	size_t size = 64;
	ssize_t e_check;

	while (1)
	{
		printf("$ ");
		e_check = getline(&buf, &size, stdin);
		if (e_check == -1)
		{
			printf("Something went wrong!\n");
			break;
		}

		printf("%s", buf);

		free(buf);
		buf = NULL;
	}
}
