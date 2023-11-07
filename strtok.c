#include "main.h"

char *_strtok(char *str, const char *delim)
{
	static char *input = NULL;
	char *token_start = input;
		
	if (str != NULL)
		input = str;

	if (input == NULL || *input == '\0')
		return NULL;

    /* Find the start of the token (skip delimiters)*/
	input += strspn(input, delim);

	if (*input == '\0')
	{
		input = NULL; /* No more tokens*/
		return NULL;
	}

    /*Find the end of the token*/

	input += strcspn(input, delim);

	if (*input != '\0')
	{
		*input = '\0'; /* Null-terminate the token*/
		input++;
	}
	else
		input = NULL; /* No more tokens*/
	
	return token_start;
}
