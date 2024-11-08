/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:38:47 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/08 18:28:53 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *stack, t_list **cmds)
{
	if (find_min(*stack) == *(int *)stack->head->content)
	{
		reverse_rotate(stack, cmds);
		swap(stack, cmds);
	}
	else if (find_max(*stack) == *(int *)stack->head->content)
	{
		rotate(stack, cmds);
		if (!is_sorted(stack->head))
			swap(stack, cmds);
	}
	else
	{
		if (find_index(*stack, find_max(*stack)) == 1)
			reverse_rotate(stack, cmds);
		else
			swap(stack, cmds);
	}
}

static void	sort_stack_a(t_push_swap *push_swap, t_list **cmds)
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
		idx = find_case(*stack_a, *stack_b);
		while (idx > -1)
		{
			if (idx == case_rr_rr(*stack_a, *stack_b, *(int *)tmp->content))
				idx = rr_rr(stack_a, stack_b, cmds, *(int *)tmp->content);
			else if (idx == case_r_r(*stack_a, *stack_b, *(int *)tmp->content))
				idx = r_r(stack_a, stack_b, cmds, *(int *)tmp->content);
			else if (idx == case_rr_r(*stack_a, *stack_b, *(int *)tmp->content))
				idx = rr_r(stack_a, stack_b, cmds, *(int *)tmp->content);
			else if (idx == case_r_rr(*stack_a, *stack_b, *(int *)tmp->content))
				idx = r_rr(stack_a, stack_b, cmds, *(int *)tmp->content);
			else
				tmp = tmp->next;
		}
	}
}

static void	sort_stack_b(t_push_swap *push_swap, t_list	**cmds)
{
	ssize_t	idx;
	t_list	*tmp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	while (push_swap->stack_a->len > 3 && !is_sorted(push_swap->stack_a->head))
	{
		tmp = stack_a->head;
		idx = find_case(*stack_b, *stack_a);
		while (idx > -1 && tmp)
		{
			if (idx == case_rr_rr(*stack_b, *stack_a, *(int *)tmp->content))
				idx = rr_rr(stack_b, stack_a, cmds, *(int *)tmp->content);
			else if (idx == case_r_r(*stack_b, *stack_a, *(int *)tmp->content))
				idx = r_r(stack_b, stack_a, cmds, *(int *)tmp->content);
			else if (idx == case_rr_r(*stack_b, *stack_a, *(int *)tmp->content))
				idx = rr_r(stack_b, stack_a, cmds, *(int *)tmp->content);
			else if (idx == case_r_rr(*stack_b, *stack_a, *(int *)tmp->content))
				idx = r_rr(stack_b, stack_a, cmds, *(int *)tmp->content);
			else
				tmp = tmp->next;
		}
	}
}

static void	setup_stack_b(t_push_swap *push_swap)
{
	if (!push_swap)
		return ;
	if (push_swap->stack_a->len > 3)
		push(push_swap->stack_a, push_swap->stack_b, &push_swap->cmds);
	if (push_swap->stack_a->len > 3 && !is_sorted(push_swap->stack_a->head))
		push(push_swap->stack_a, push_swap->stack_b, &push_swap->cmds);
	if (push_swap->stack_a->len > 3 && !is_sorted(push_swap->stack_a->head))
		sort_stack_b(push_swap, &push_swap->cmds);
	if (push_swap->stack_a->len == 3 && !is_sorted(push_swap->stack_a->head))
		sort_3(push_swap->stack_a, &push_swap->cmds);
}

t_bool	sort_push_swap(t_push_swap *push_swap)
{
	ssize_t	idx;
	t_stack	*stack_a;

	stack_a = push_swap->stack_a;
	if (!push_swap)
		return (False);
	if (stack_a->len == 2)
		swap(stack_a, &push_swap->cmds);
	else
	{
		setup_stack_b(push_swap);
		sort_stack_a(push_swap, &push_swap->cmds);
		idx = find_index(*stack_a, find_min(*stack_a));
		if (idx < (ssize_t)stack_a->len - idx)
			while (*(int *)stack_a->head->content != find_min(*stack_a))
				rotate(stack_a, &push_swap->cmds);
		else
			while (*(int *)stack_a->head->content != find_min(*stack_a))
				reverse_rotate(stack_a, &push_swap->cmds);
	}
	return (True);
}
