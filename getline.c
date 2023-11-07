#include "main.h"

/**
 * _getline - reads an input from keyboard
 * @input: A pointer to a pointer to characters to store the input line
 * @n: pointer to a variable tracking allocated memory size
 * @status: exit status in case of error
 * Return: inputted_chars or -1
 */
ssize_t _getline(char **input, size_t *n, FILE *stream)
{
	ssize_t number_of_characters_read;
	
	number_of_characters_read = getline(input, n, stream);

	if (number_of_characters_read == -1)
	{
		free(*input);
		*input = NULL;
	}
	
	else if (number_of_characters_read == 1 && (*input)[0] == '\n')
	{
		free(*input);
		*input = NULL;
	}
	else
	{
		if ((*input)[number_of_characters_read - 1] == '\n')
		{
			(*input)[number_of_characters_read - 1] = '\0';
		}
	}

	return number_of_characters_read;
}
