#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	child_pid = fork();
	if (child_pid == 0)
		execve(argv[0], argv, NULL);
	else
	{
		wait(NULL);
		child_pid = fork();
		if (child_pid == 0)
			execve(argv[0], argv, NULL);
		else
		{
			wait(NULL);
			child_pid = fork();
			if (child_pid == 0)
				execve(argv[0], argv, NULL);
			else
			{
				wait(NULL);
				child_pid = fork();
				if (child_pid == 0)
				{
					execve(argv[0], argv, NULL);
				}
				else
				{
					wait(NULL);
					execve(argv[0], argv, NULL);
				}
			}
		}
	}
	return (0);
}
