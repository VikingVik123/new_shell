#include "main.h"

char **parse_input(char *input)
{
	int token_count = 0;
	char **tokens = NULL;
	const char *delim = "\n";
	
	char *token = strtok(input, delim);
	
	while (token)
	{
		tokens = malloc((token_count + 1) * sizeof(char *));
		tokens[token_count] = _strdup(token);
		token_count++;
		token = strtok(NULL, delim);
	}
	
	tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
	tokens[token_count] = NULL;

	return tokens;
}
