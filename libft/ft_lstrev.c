//
// Created by Halcyon abrah Ramirez on 3/27/18.
//

#include "libft.h"

void		ft_lstrev(t_list **lst)
{
	t_list	*current;
	t_list	*prev;
	t_list 	*next;

	current = *lst;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*lst = prev;

}