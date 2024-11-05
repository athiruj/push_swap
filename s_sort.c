/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:38:47 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 19:20:42 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_a(t_push_swap *push_swap)
{
	ssize_t	idx;
	t_list	*tmp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	while (stack_b->len)
	{
		tmp = stack_b->head;
		idx = find_case(stack_a, stack_a);
		while (idx > -1)
		{
			if (idx == case_r_r(stack_a, stack_b, *(int *)tmp->content))
				idx = sort_case_r_r(stack_a, stack_b, push_swap->cmds);
			else if (idx == case_rr_rr(stack_a, stack_b, *(int *)tmp->content))
				idx = sort_case_rr_rr(stack_a, stack_b, push_swap->cmds);
			else if (idx == case_rr_r(stack_a, stack_b, *(int *)tmp->content))
				idx = sort_case_rr_r(stack_a, stack_b, push_swap->cmds);
			else if (idx == case_r_rr(stack_a, stack_b, *(int *)tmp->content))
				idx = sort_case_r_rr(stack_a, stack_b, push_swap->cmds);
			else
				tmp = tmp->next;
		}
	}
}

static void	sort_stack_b(t_push_swap *push_swap)
{
	ssize_t	idx;
	t_list	*tmp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	while (stack_a->len > 3 && !is_sorted(stack_a))
	{
		tmp = stack_a->head;
		idx = find_case(stack_b, stack_a);
		while (idx > -1)
		{
			if (idx == case_r_r(stack_b, stack_a, *(int *)tmp->content))
				idx = sort_case_r_r(stack_b, stack_a, push_swap->cmds);
			else if (idx == case_rr_rr(stack_b, stack_a, *(int *)tmp->content))
				idx = sort_case_rr_rr(stack_b, stack_a, push_swap->cmds);
			else if (idx == case_rr_r(stack_b, stack_a, *(int *)tmp->content))
				idx = sort_case_rr_r(stack_b, stack_a, push_swap->cmds);
			else if (idx == case_r_rr(stack_b, stack_a, *(int *)tmp->content))
				idx = sort_case_r_rr(stack_b, stack_a, push_swap->cmds);
			else
				tmp = tmp->next;
		}
	}
}

static void	setup_stack_b(t_push_swap *push_swap)
{
	if (!push_swap)
		return (False);
	if (push_swap->stack_a->len > 3)
		push(push_swap->stack_a, push_swap->stack_b, &push_swap->cmds);
	if (push_swap->stack_a->len > 3 && !is_sorted(push_swap->stack_a))
		push(push_swap->stack_a, push_swap->stack_b, &push_swap->cmds);
	if (push_swap->stack_a->len > 3 && !is_sorted(push_swap->stack_a))
		sort_stack_b(push_swap);
}

t_bool	sort_push_swap(t_push_swap *push_swap)
{
	ssize_t	idx;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	if (!push_swap)
		return (False);
	if (stack_a->len == 2)
		swap(stack_a, &push_swap->cmds);
	else
	{
		setup_stack_b(push_swap);
		sort_stack_a(push_swap);
		idx = find_index(stack_a, find_min(stack_a));
		if (idx < stack_a->len - idx)
			while (*(int *)stack_a->head->content != find_min(stack_a))
				rotate(stack_a, push_swap->cmds);
		else
			while (*(int *)stack_a->head->content != find_min(stack_a))
				reverse_rotate(stack_a, push_swap->cmds);
	}
	return (True);
}

