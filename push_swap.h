/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:09 by athi              #+#    #+#             */
/*   Updated: 2024/10/30 14:44:48 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/*
	head: head of stack
	tail: tail stack
	len: number of stack
*/
typedef struct s_stack
{
	size_t	len;
	t_list	*head;
	t_list	*before_tail;
	t_list	*tail;
}	t_stack;

/*
	stack_a: a stack
	stack_b: b stack
*/
typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*cmds;
}	t_push_swap;

t_bool	stack_checker(t_list *lst);
t_bool	initial_stack(t_stack *stack, int argc, char *argv[]);
t_bool	initial_push_swap(t_push_swap *push_swap, int argc, char *argv[]);
t_bool	free_children(t_push_swap *push_swap);
t_bool	free_fail_children(t_push_swap *push_swap);
t_bool	free_stack(t_stack *stack);
t_bool	free_arr(char **arr);

#endif