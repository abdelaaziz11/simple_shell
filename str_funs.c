#include "main.h"
/**
 * _str_len - determines the length of a string
 * @str: Pointer points to a string
 * Return: str length
*/
int _str_len(char *str)
{
	int length = 0;

	for (; *str != '\0'; str++, length++)
		;
	return (length);
}
/**
 * count_args - counts arguments from the command line
 * @line: The command line
 * Return: number of arguments
 */
int count_args(char *line)
{
	int i, searchSpc = 1, num_arg = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && searchSpc == 1)
		{
			num_arg++;
			searchSpc = 0;
		}
		if (line[i + 1] == ' ')
			searchSpc = 1;
	}
	return (num_arg);
}

/**
 * _str_dup - duplicates a string to another one
 * @str: the string
 * Return: buffer
 */
char *_str_dup(char *str)
{
	int length = 0, j = 0;
	char *buf;

	if (!str)
		return (NULL);
	for (j = 0; str[length] != '\0'; j++)
		length++;
	buf = malloc(sizeof(char) * (length + 1));
	if (!buf)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		buf[j] = str[j];
	buf[length] = '\0';
	return (buf);
}

/**
 * _str_cpy - copies a string to another
 * @src: The source string
 * @dest: The destination string
 * Return: On success, the destination string
*/
char *_str_cpy(char *dest, char *src)
{
	int l = 0, i;

	for (i = 0; src[l] != '\0'; i++)
		l++;
	i = 0;
	while (i <= l)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _str_cat - concatinate the strings
 * @dest: Destination string
 * @src: Source string
 * Return: The resulte of string
 */
char *_str_cat(char *dest, char *src)
{
	int i = 0;

	for (; *dest != '\0'; i++)
		dest++;
	for (; *src != '\0'; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	dest -= i;
	return (dest);
}

