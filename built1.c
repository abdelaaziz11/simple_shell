#include "shell.h"

/**
 * _my_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _my_history(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * my_unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int my_unset_alias(info_t *info, char *str)
{
	char *equal_sign_position, original_character;
	int deletion_result;

	equal_sign_position = _strchr(str, '=');
	if (!equal_sign_position)
	return (1);
	original_character = *equal_sign_position;
	*equal_sign_position = '\0';
	deletion_result = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equal_sign_position = original_character;
	return (deletion_result);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *equal_sign_position;

	equal_sign_position = _strchr(str, '=');
	if (!equal_sign_position)
		return (1);
	if (!*++equal_sign_position)
		return (my_unset_alias(info, str));
	my_unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * my_print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int my_print_alias(list_t *node)
{
	char *equal_sign_position = NULL, *iterator = NULL;

	if (node)
	{
		equal_sign_position = _strchr(node->str, '=');
		for (iterator = node->str; iterator <= equal_sign_position; iterator++)
			_putchar(*iterator);
		_putchar('\'');
		_puts(equal_sign_position + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _my_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _my_alias(info_t *info)
{
	int i = 0;
	char *equal_sign_position = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			my_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_sign_position = _strchr(info->argv[i], '=');
		if (equal_sign_position)
			set_alias(info, info->argv[i]);
		else
			my_print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}

