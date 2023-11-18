#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	for (; h; h = h->next)
		count++;
	return (count);
}
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t len = list_len(head), str_len, j, i;
	char **strs;

	if (!head || len == 0)
		return (NULL);
	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	for (i = 0; i < len; i++, head = head->next)
	{
		str_len = _strlen(head->str);
		strs[i] = malloc(str_len + 1);
		if (!strs[i])
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		_strcpy(strs[i], head->str);
	}
	strs[len] = NULL;
	return (strs);
}
/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	for (; h; h = h->next, i++)
		printf("%lu: %s\n", (unsigned long)h->num, (h->str ? h->str : "(nil)"));
	return (i);
}
/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	const char *p = NULL;

	for (; node; node = node->next)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
	}
	return (NULL);
}
/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	for (; head; head = head->next, index++)
	{
		if (head == node)
			return (index);
	}
	return (-1);
}
