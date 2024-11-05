/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_initialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:05:36 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 13:13:01 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	push_stack(t_list *stack, char *str)
{
	t_list	*tmp_stack;

	if (!stack->content)
		stack->content = str;
	else
	{
		tmp_stack = ft_lstnew(str);
		if (!tmp_stack)
			return (False);
		ft_lstadd_back(&stack, tmp_stack);
	}
	return (True);
}

static t_bool	build_stack(t_list	*stack, int argc, char *argv[])
{
	char	**tmp_arr;
	size_t	i;

	while (*++argv && --argc)
	{
		tmp_arr = ft_split(*argv, ' ');
		if (!tmp_arr || !(tmp_arr[0]))
		{
			ft_putstr_fd("ERROR\n", 1);
			return (!free_arr(tmp_arr));
		}
		i = 0;
		while (tmp_arr[i])
			if (!push_stack(stack, tmp_arr[i++]))
				return (!free_arr(tmp_arr));
		free(tmp_arr);
	}
	return (True);
}

t_bool	initial_stack(t_stack *stack, char *name, int argc, char *argv[])
{
	size_t	i;
	t_list	*tmp_lst;

	stack->head = (t_list *)malloc(sizeof(t_stack));
	if (!stack->head)
		return (False);
	if (!build_stack(stack->head, argc, argv)
		|| !stack_checker(stack->head))
	{
		free_stack(stack);
		return (False);
	}
	stack->name = name;
	stack->len = ft_lstsize(stack->head);
	i = 1;
	tmp_lst = stack->head;
	while (i < stack->len - 1)
	{
		tmp_lst = tmp_lst->next;
		i++;
	}
	stack->tail = tmp_lst->next;
	return (True);
}

t_bool	initial_push_swap(t_push_swap *push_swap, int argc, char *argv[])
{
	if (!push_swap)
		return (False);
	push_swap->stack_a = (t_stack *)malloc(sizeof(t_stack));
	push_swap->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!push_swap->stack_a || !push_swap->stack_b)
		return (!free_fail_children(push_swap));
	push_swap->stack_b->name = "b";
	push_swap->stack_b->len = 0;
	push_swap->stack_b->head = NULL;
	push_swap->stack_b->tail = NULL;
	if (!initial_stack(push_swap->stack_a, "a", argc, argv))
		return (!free_fail_children(push_swap));
	return (True);
}
