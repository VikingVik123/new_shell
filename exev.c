#include "main.h"

/**
 * exec - function to execute commands
 * @argv: argument vector
 * return: void
 */

void exec(char **argv, char **environ)
{
	char *path;
	char *path_copy;
	char *command;
	char *path_token;
	

    if (argv) {
        command = argv[0];

        /* Check if the command contains a full path */
        if (_strchr(command, '/') != NULL) {
            if (execve(command, argv, environ) == -1) {
                perror("Error:");
                exit(1);
            }
        } else {
            path = _getenv("PATH", environ);

            if (path == NULL) {
                /* PATH environment variable not set */
                perror("Not found");
                exit(1);
            }

            path_copy = _strdup(path);

            if (path_copy == NULL) {
                perror("Error:");
                exit(1);
            }

            path_token = _strtok(path_copy, ":");

            while (path_token != NULL) {
                size_t directory_length = _strlen(path_token);
                size_t command_length = _strlen(command);
                size_t file_path_length = directory_length + 1 + command_length + 1; /* +1 for '/' and +1 for '\0' */
                char *file_path = malloc(file_path_length);

                if (file_path == NULL) {
                    free(path_copy);
                    perror("Error:");
                    exit(1);
                }

                _strcpy(file_path, path_token);
                _strcat(file_path, "/");
                _strcat(file_path, command);

                if (execve(file_path, argv, environ) == -1) {
                    free(file_path);
                    path_token = strtok(NULL, ":");
                } else {
                    free(file_path);
                    free(path_copy);
                    perror("Error:");
                    exit(1);
                }
            }

            free(path_copy);
            perror("Not found");
            exit(0);
        }
    }
}
