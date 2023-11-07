#include "main.h"

/**
 * _environ - function that calls the env func
 * @env: functions that calls the env
 *
 * return: void
 */

void _environ(char **env)
{
	/*Iterate through the environment variables and print them*/

	int i = 0;

	while (env[i] != NULL)
	{
		_puts(env[i]);
		i++;
	}
}
