/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:35:17 by Degef             #+#    #+#             */
/*   Updated: 2023/03/23 18:50:56 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	handler(t_node **a, char ***str)
{
	free_linked_list(a);
	free_array(str);
	message();
}

/*
fill_a:
	stores all the arguments into stack a
	if a is null, new node will asign to it
	else, the new node will put at the end
*/

void	fill_a(char **storage, t_node **a)
{
	long	num;
	char	**str;
	int		i;
	t_node	*nod;

	i = -1;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[++i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			handler(a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->sort_index = 0;
		if (!*a)
		(*a) = nod;
		else
			lstlast(*a)->next = nod;
	}
	free_array(&str);
}

/*
lstlast:
	it returns the last node
*/
t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
is_sorted:
	it checks whethere the stack is sorted or not, 
	if its, it returns 1 else 0
	note: if the stack has no element, it returns 1
*/

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
