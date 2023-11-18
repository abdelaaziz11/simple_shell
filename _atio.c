#include "shell.h"

/**
 * interactive_funtion - returns true if shell is interactive_funtion mode
 * @info: struct address
 *
 * Return: 1 if interactive_funtion mode, 0 otherwise
 */
int interactive_funtion(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delimiter - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim)
{
	for (; *delim; delim++)
	{
		if (*delim == c)
		return (1);
	}
	return (0);
}
/**
 *_isalphabet - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalphabet(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	output = (sign == -1) ? -result : result;
	return (output);
}
