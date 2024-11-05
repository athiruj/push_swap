/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:50 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 18:31:56 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	case_r_r(t_stack *stack1, t_stack *stack2, int num)
{
	ssize_t	idx;

	if (stack1->name == "a")
		idx = find_index_a(stack1, num);
	else if (stack1->name == "b")
		idx = find_index_b(stack1, num);
	if (idx < find_index(stack1, num))
		idx = find_index(stack1, num);
	return (idx);
}

ssize_t	case_rr_rr(t_stack *stack1, t_stack *stack2, int num)
{
	ssize_t	idx;

	idx = 0;
	if (stack1->name == "a" && find_index_a(stack1, num))
		idx = stack1->len - find_index_a(stack1, num);
	else if (stack1->name == "b" && find_index_b(stack1, num))
		idx = stack1->len - find_index_b(stack1, num);
	if ((idx < stack2->len - find_index(stack2, num))
		&& find_index(stack2, num))
		idx = stack2->len - find_index(stack2, 1);
	return (idx);
}

ssize_t	case_rr_r(t_stack *stack1, t_stack *stack2, int num)
{
	ssize_t	idx;

	idx = 0;
	if (stack1->name == "a")
	{
		if (find_index_a(stack2, num))
			idx = stack1->len - find_index_a(stack1, num);
		idx = find_index(stack2, num) + idx;
	}
	else if (stack1->name == "b")
	{
		if (find_index(stack1, num))
			idx = stack2->len - find_index(stack2, num);
		idx = find_index_b(stack1, num) + idx;
	}
	return (idx);
}

ssize_t	case_r_rr(t_stack *stack1, t_stack *stack2, int num)
{
	ssize_t	idx;

	idx = 0;
	if (stack1->name == "a")
	{
		if (find_index(stack2, num))
			idx = stack2->len - find_index(stack2, num);
		idx = find_index_b(stack1, num) + idx;
	}
	else if (stack1->name == "b")
	{
		if (find_index_b(stack1, num))
			idx = stack1->len - find_index_b(stack1, num);
		idx = find_index(stack2, num) + idx;
	}
	return (idx);
}

ssize_t	find_case(t_stack *stack1, t_stack *stack2)
{
	ssize_t	idx;
	t_list	*tmp;

	tmp = stack2;
	idx = case_rra_rrb(stack1, stack2, *(int *)stack2->head->content);
	while (tmp)
	{
		if (idx > case_r_r(stack1, stack2, *(int *)tmp->content))
			idx = case_r_r(stack1, stack2, *(int *)tmp->content);
		if (idx > case_rr_rr(stack1, stack2, *(int *)tmp->content))
			idx = case_rr_rr(stack1, stack2, *(int *)tmp->content);
		if (idx > case_r_rr(stack1, stack2, *(int *)tmp->content))
			idx = case_r_rr(stack1, stack2, *(int *)tmp->content);
		if (idx > case_rr_r(stack1, stack2, *(int *)tmp->content))
			idx = case_rr_r(stack1, stack2, *(int *)tmp->content);
		tmp = tmp->next;
	}
	return (idx);
}