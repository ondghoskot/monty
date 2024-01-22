#include "monty.h"

/**
 * check_number - checks if string is a number
 * @string: the given string
 * Return: 1 if true and 0 if false
 */
int check_number(char *string)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
		{
			if (str[i + 1] == '\0')
				return (0);
		}
		else if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 * _free - frees all the memory that is currently allocated
 * @stack: pointer to dll
 * Return: nothing
 */
void _free(stack_t *stack)
{
	stack_t *remove = stack;

	while (stack != NULL)
	{
		stack = stack->next;
		free(remove);
		remove = stack;
	}
	free(mem.token);
	fclose(mem.pScript);
}
