#include "main.h"
/**
 * search_in_path - function to access the PATH
 *
 * return: void
 */
    char *search_in_path(const char *command, char **environ) {
    char *path_copy, *path_token;
    struct stat buffer;


    char *path = _getenv("PATH", environ);

    if (path == NULL)
	    return NULL; /* PATH environment variable not set */
    
    path_copy = _strdup(path);

    if (path_copy == NULL)
	    return NULL; /* Memory allocation failed */

    path_token = strtok(path_copy, ":");

    while (path_token != NULL) {
        size_t directory_length = _strlen(path_token);
        size_t command_length = _strlen(command);
        size_t file_path_length = directory_length + 1 + command_length + 1;
        char *file_path = malloc(file_path_length);

        if (file_path == NULL) {
            free(path_copy);
            return NULL; /* Memory allocation failed */
        }
        _strcpy(file_path, path_token);
        _strcat(file_path, "/");
        _strcat(file_path, command);

        if (stat(file_path, &buffer) == 0) {
            free(path_copy); /* Free path_copy since you're returning file_path */
            return file_path;
        } else {
            free(file_path);
            path_token = strtok(NULL, ":");
        }
    }
    free(path_copy);
    return NULL; /* Command not found in PATH */
}
