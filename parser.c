#include "main.h"

char **parse_input(char *input)
{
	int token_count = 0;
	char **tokens = NULL;
	char **new_tokens = NULL;
	const char *delim = "\n";
	char *token = strtok(input, delim);

	while (token)
	{
		new_tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		
		if (new_tokens == NULL)
		{
			/*Handle realloc failure*/
			free(tokens); /*Free the previously allocated memory*/
			return NULL;
		}
		tokens = new_tokens;
		tokens[token_count] = _strdup(token);

		if (tokens[token_count] == NULL)
		{
			/*Handle strdup failure*/
			free(tokens); /*Free the previously allocated memory*/
			return NULL;
		}
		token_count++;
		token = strtok(NULL, delim);
	}

    /*Don't free tokens here; the caller should handle memory management*/
	return tokens;
}

