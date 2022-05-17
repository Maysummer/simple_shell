#include "main.h"
/**
 * make_list_version2 - makes a linked list by adding node at the end of list
 * @head: head of list
 * @p_dir: sting to copy to for new node
 * Return: err or 0
 */
int make_list_version2(path_l **head, char *p_dir[])
{
	path_l *new, *save, *prev;
	int i = 1;

	if (*head == NULL)
	{
		*head = malloc(sizeof(path_l));
		if (!*head)
		{
			perror("Error");
			exit(98);
		}
		(*head)->p_dir = _strdup(p_dir[0]);
		(*head)->next = NULL;
	}

	while(p_dir[i])
	{
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
		new->p_dir = _strdup(p_dir[i]);
		new->next = NULL;
		prev->next = new;
		*head = save;
		i++;
	}
	return (0);
}

