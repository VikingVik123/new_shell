#include "main.h"

int lineop(ssize_t line, char *input)
{
	char *token;
	char *delim = "\n";
	char *input_cpy;

	input_cpy = _strdup(input);
	if (input == NULL)
	{
		free(input);
		input = NULL;
		
	}
	if (line == -1)
	{
		free(input);
		input = NULL;
		exit(1);
	}
	else
	{
		token = strtok(input_cpy, delim);
		while (token != NULL)
			token = strtok(NULL, delim);
	}
	free(input_cpy);
	return (0);
}
