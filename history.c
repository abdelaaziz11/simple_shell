#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir = NULL;
	size_t dir_len = _strlen(dir);
	size_t hist_file_len = _strlen(HIST_FILE);

	dir = _get_env(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (dir_len + hist_file_len + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	buf[dir_len] = '/';
	buf[dir_len + 1] = '\0';
	_strcat(buf, HIST_FILE);
	return (buf);
}
/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	FILE *file;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	file = fopen(filename, "w");
	free(filename);
	if (!file)
		return (-1);
	for (node = info->history; node; node = node->next)
		fprintf(file, "%s\n", node->str);
	fclose(file);
	return (1);
}
/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fstat(fd, &st) != 0 || st.st_size < 2)
	{
		close(fd);
		return (0);
	}
	fsize = st.st_size;
	buf = malloc(sizeof(char) * (fsize + 1));
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}
	close(fd);
	for (i = 0; i < fsize; i++)
	{
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);
	if (!info->history)
		info->history = node;
	return (0);
}
/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
	node->num = i++;
	node = node->next;
	}
	info->histcount = i;
	return (i);
}

