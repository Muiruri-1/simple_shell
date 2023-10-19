#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure with potential args
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - get value of environment var
 * @info: Structure with argument
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *n;

	while (node)
	{
		n = starts_with(node->str, name);
		if (n && *n)
			return (n);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new/modify existing environment variable
 * @info: maintains constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("wrong number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes environment variable
 * @info: maintains constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("very few args.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}

/**
 * pop_env_list - populates link list
 * @info: maintains constant function prototype.
 * Return: Always 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}
