#include "main.h"

/**
 * _strlen - checks string length
 * @s: string
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * _puts - inserts char
 * @str : character to be inserted
 * return: char if successful
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	
}


/**
 * _strcpy - copies the string pointed to by src
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int len, i;
	
	i = 0;
	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	 for (i = 0; i < len; i++)
        {
                dest[i] = src[i];
        }

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - string comparison
 * @s1: 1st string to compare
 * @s2: 2nd string to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
