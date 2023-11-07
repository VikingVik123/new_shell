#include "main.h"

char *search_in_current_directory(const char *command)
{
	struct stat buffer;

	if (stat(command, &buffer) == 0)
	{
		return (_strdup(command));
	}

	return (NULL); /* Command not found in the current directory */
}
