#include "main.h"
/**
 * search_in_path - function to access the PATH
 *
 * return: void
 */
char *search_in_path(const char *command, char **environ)
{
	char *path_copy, *path_token, *file_path;
	char *path = _getenv("PATH", environ);

	if (path == NULL)
		return (NULL); /* PATH environment variable not set */

	path_copy = _strdup(path);

	if (path_copy == NULL)
		return (NULL); /* Memory allocation failed */

	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		file_path = _strcat3(path_token, "/", command);

		if (access(file_path, X_OK) == 0)
		{
			free(path_copy);
			return (file_path); /* Found executable in the path */
        	}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL); /* Command not found in PATH */
}
