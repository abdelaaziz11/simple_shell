#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i;
	if (!str)
		return;
	for (i = 0; str[i] != '\0'; i++)
		_eput_char(str[i]);
}
/**
 * _eput_char - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eput_char(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (i >= WRITE_BUF_SIZE || c == BUF_FLUSH)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
		return (1);
	}
	return (0);
}
/**
 * _put_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	else
	{
	write(fd, buf, i);
	i = 0;
	}
	return (1);
}
/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
	return (0);
	for (; *str; str++)
		count += _put_fd(*str, fd);
	return (count);
}
