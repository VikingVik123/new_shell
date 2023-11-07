#include "main.h"

int main(int ac, char **av, char **environ)
{
	ssize_t line = 0;
	size_t n = 0;
	char *input = NULL;
	/*char *input_cpy = NULL;*/
	/*char *prompt;*/
	/*int num_token = 0;*/
	/*char *token;*/
	/*const char *delim = "\n";*/
	char **argv;
	/*int i = 0;*/
	(void)ac;
	(void)av;

	while (1)
	{
		line = _getline(&input, &n, stdin);
		
		if (line <= 0)
        	{
            		free(input);
            		break;
        	}
        	argv = parse_input(input);

        	if (argv != NULL)
        	{
            		if (_strcmp(argv[0], "env") == 0)
            		{
                		_environ(environ);
            		}
            		else
            		{
				char *full_path = search_in_path(argv[0], environ);
                
				if (full_path != NULL)
				{
                    			argv[0] = full_path;
                    			_fork(argv, environ);
            			}
				else
					perror("command not found");
				free(argv);
			}
        	}

    	}

    return (0);
}
