#include "shell.h"

/**
 * _my_env - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _my_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _get_env - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	 char *position;

	while (node)
	{
		position = starts_with(node->str, name);
		if (position && *position)
			return (position);
		node = node->next;
	}
	return (NULL);
}
/**
 * _my_setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _my_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	return (_setenv(info, info->argv[1], info->argv[2]) == 0 ? 1 : 0);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int success = 0, i;

	if (info->argc <= 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i < info->argc; i++)
	{
	if (_unsetenv(info, info->argv[i]) == 0)
		success = 1;
	}
	return (success ? 0 : 1);
}
/**
 * _populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
