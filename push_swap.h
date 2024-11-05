/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:09 by athi              #+#    #+#             */
/*   Updated: 2024/11/05 19:10:32 by atkaewse         ###   ########.fr       */
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

/* utility functions */
/*  checker functions */
t_bool	stack_checker(t_list *lst);
t_bool	is_sorted(t_list *stack);

/*  initialize function */
t_bool	initial_stack(t_stack *stack, char *name, int argc, char *argv[]);
t_bool	initial_push_swap(t_push_swap *push_swap, int argc, char *argv[]);

/*  free functions */
t_bool	free_children(t_push_swap *push_swap);
t_bool	free_fail_children(t_push_swap *push_swap);
t_bool	free_stack(t_stack *stack);
t_bool	free_arr(char **arr);

/*  util functions */
t_list	*before_tail(t_list *lst);
void	add_cmd(t_list	**lst, char *cmd);
void	print_cmds(t_list *cmds);

/* operator functions */
void	push(t_stack *from_stack, t_stack *to_stack, t_list **cmds);
void	r_rotate(t_stack *stack_a, t_stack *stack_b, t_list **cmds);
void	reverse_rotate(t_stack *stack, t_list **cmds);
void	rotate(t_stack *stack, t_list **cmds);
void	r_reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_list **cmds);
void	swap(t_stack *stack, t_list **cmds);
void	s_swap(t_stack *stack_a, t_stack *stack_b, t_list **cmds);

/* sort functions */
t_bool	sort_push_swap(t_push_swap *push_swap);

/* 	find functions */
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
ssize_t	find_index(t_stack *stack, int num);
ssize_t	find_index_a(t_stack *stack, int num);
ssize_t	find_index_b(t_stack *stack, int num);

/* 	in case functions */
ssize_t	find_case(t_stack *stack1, t_stack *stack2);
ssize_t	case_r_r(t_stack *stack1, t_stack *stack2, int num);
ssize_t	case_rr_rr(t_stack *stack1, t_stack *stack2, int num);
ssize_t	case_rr_r(t_stack *stack1, t_stack *stack2, int num);
ssize_t	case_r_rr(t_stack *stack1, t_stack *stack2, int num);

/* 	in case sorting functions */
ssize_t	sort_case_r_r(t_stack *from_stack, t_stack *to_stack, t_list **cmds);
ssize_t	sort_case_rr_rr(t_stack *from_stack, t_stack *to_stack, t_list **cmds);
ssize_t	sort_case_rr_r(t_stack *from_stack, t_stack *to_stack, t_list **cmds);
ssize_t	sort_case_r_rr(t_stack *from_stack, t_stack *to_stack, t_list **cmds);

#endif