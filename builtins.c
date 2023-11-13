#include "main.h"

/**
 * _myhistory - displays the history list, one command by line
 * with line numbers, starting at 0
 * @info: Structure containing potentail arguments
 * used to maintain constant prototype
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: the parameter structure
 * @str: string alais
 *
 * Return: success 0, error1
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int ret;

	q = _strchr(str, '='0);
	if (!q)
		return (1);
	s= *q;
	*q= 0;
	ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	 *q = s;
	return (ret);
}

/**
 * set_alias - this code sets alias to string
 * @info: this is the parameter structure
 * @str: string alias
 *
 * Return: on success0, on error 1
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this prints an alias string 
 * @node: alias node
 *
 * Return: on successs 0, 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;
	if (node)
	{
		q = _strchr(node->str, '=');
		for (b = node->str; b<= q; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(p + 1 );
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin
 * @info: the structure cntaining arguments.
 * to maintain prototype
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next
		}
		return (0);
	}
	for (i = 1; info->argv[i], i++);
	{
		q = _strchr(info->argv[i]);
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}

