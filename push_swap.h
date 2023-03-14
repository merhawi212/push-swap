/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:56:10 by Degef             #+#    #+#             */
/*   Updated: 2023/03/14 16:50:50 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct t_list
{
	int				data;
	int				sort_index;
	struct t_list	*next;
}					t_node;

// utils
t_node	*lstlast(t_node *lst);
int		is_sorted(t_node *stack);
void	message(int nb);
void	create_linked_list(char *storage, t_node **a);

//validate_args
int		check_dup(char *str);
int		check_invalid_args(char *str);

// operations
void	swap(t_node *stack, char *str);
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	push_a(t_node **stack_1, t_node **stack_2, char *str);

// put sorting index
int		find_len(t_node *stack);
void	sort_int_array(int **tab, int size);
void	assign_index(int len, t_node **stack, int *sorted_list);
void	put_sorting_index(t_node **stack);
int		find_midpoint(t_node *stack);

// count moves
int		count_forward_moves(t_node *stack, int point);
int		count_backward_moves(t_node *stack, int point);

// find_min_max
void	find_min_and_max(int *a_min, int *a_max, t_node *temp);
void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
									t_node **a, t_node **b);

#endif