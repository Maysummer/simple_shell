#include "main.h"
/**
 * make_list - makes a linked list by adding node at the end of list
 * @head: head of list
 * @p_dir: sting to copy to for new node
 * Return: err or 0
 */
int make_list(path_l **head, char *p_dir)
{
	path_l *new, *save, *prev;

	if (*head == NULL)
	{
		*head = malloc(sizeof(path_l));
		if (!*head)
		{
			perror("Error");
			exit(98);
		}
		(*head)->p_dir = _strdup(p_dir);
		(*head)->next = NULL;
	}

	new = malloc(sizeof(path_l));
	if (!new)
	{
		perror("Error");
		exit(98);
	}

	save = *head;
	while (*head)
	{
		prev = *head;
		*head = (*head)->next;
	}
	new->p_dir = _strdup(p_dir);
	new->next = NULL;
	prev->next = new;
	*head = save;
	return (0);
}

