#include "main.h"

/**
 * _fork - creates a new process
 * @argv: contains argument to carry out
 * return: void
 */

void _fork(char **argv, char **environ)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		_exits("FAILURE");
	}
	else if (child_pid == 0)
	{
		/*This is the child process*/
		exec(argv, environ);
		perror("Error:");
		exit(0);
	}
	else
	{
		wait(&status);
	}

}
