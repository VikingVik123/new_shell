#include "main.h"
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;

    *dest = '\0';
    return ret;
}

/**
 * _strchr - searchs for the first occurrence of a character
 * @str: source buffer
 * return: NULL
 */
char* _strchr(const char* str, int character)
{
    while (*str != '\0')
    {
        if (*str == character)
	{
            return (char*)str;
        }
        str++;
    }
    if (character == '\0')
    {
        return (char*)str;
    }
    return NULL;
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
