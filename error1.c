#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	unsigned long int result = 0;
	int sign = 1;

	if (!s)
		return (-1);
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '+' || *s == '-')
	{
		sign = (*s == '-') ? -1 : 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		if (result > INT_MAX)
			return (-1);
		s++;
	}
	return ((int)(result * sign));
}
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eput_char : _putchar;
	int count = 0, divisor = 1;

	if (input < 0)
	{
		 __putchar('-');
		return (1 + print_d(-input, fd));
	}
	while (divisor <= input / 10)
		divisor *= 10;
	while (divisor > 0)
	{
		__putchar('0' + input / divisor);
		input %= divisor;
		divisor /= 10;
		count++;
	}
	return (count);
}
/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	char *ptr = &buffer[49];
	unsigned long n;

	*ptr = '\0';
	n  = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;
	do {
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);
	if (num < 0 && !(flags & CONVERT_UNSIGNED))
		*--ptr = '-';
	return (strdup(ptr));
}
/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
