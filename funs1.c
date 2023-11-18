#include "main.h"
/**
 * _strn_cmp - compares two strings n
 * @str1: String first
 * @str2: String second
 * @n: index
 * Return: 0 if success, -1 if failure
*/
int _strn_cmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}
/**
 * getbuilt_in - Retrieve built -in commands
 * @str: The command of string
 * Return: Always 0
 */
int getbuilt_in(char *str)
{
	return ((_str_len(str) == 4 && _strn_cmp(str, "exit", 4) == 0) ? 0 :
			(_str_len(str) == 3 && _strn_cmp(str, "env", 3) == 0) ? 1 : -1);
}

