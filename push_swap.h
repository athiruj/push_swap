/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:09 by athi              #+#    #+#             */
/*   Updated: 2024/11/02 21:26:41 by atkaewse         ###   ########.fr       */
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
	char	*name;
	size_t	len;
	t_list	*head;
	t_list	*tail;
}	t_stack;

/*
	stack_a: a stack
	stack_b: b stack
	cmds: commands
*/
typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*cmds;
}	t_push_swap;

t_bool	stack_checker(t_list *lst);
t_bool	initial_stack(t_stack *stack, char *name, int argc, char *argv[]);
t_bool	initial_push_swap(t_push_swap *push_swap, int argc, char *argv[]);
t_bool	free_children(t_push_swap *push_swap);
t_bool	free_fail_children(t_push_swap *push_swap);
t_bool	free_stack(t_stack *stack);
t_bool	free_arr(char **arr);

t_bool	push(t_stack *from_stack, t_stack *to_stack, t_list **cmds);
void	add_cmd(t_list	**lst, char *cmd);

#endif