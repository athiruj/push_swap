/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:50 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/06 12:32:42 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	case_r_r(t_stack stack1, t_stack stack2, int n)
{
	ssize_t	idx;

	idx = 0;
	if (!ft_strcmp(stack1.name, "a"))
		idx = find_index_a(stack1, n);
	else if (!ft_strcmp(stack1.name, "b"))
		idx = find_index_b(stack1, n);
	if (idx < find_index(stack2, n))
		idx = find_index(stack2, n);
	return (idx);
}

ssize_t	case_rr_rr(t_stack stack1, t_stack stack2, int n)
{
	ssize_t	idx;

	idx = 0;
	if (!ft_strcmp(stack1.name, "a") && find_index_a(stack1, n))
		idx = stack1.len - find_index_a(stack1, n);
	else if (!ft_strcmp(stack1.name, "b") && find_index_b(stack1, n))
		idx = stack1.len - find_index_b(stack1, n);
	if ((idx < (ssize_t)stack2.len - find_index(stack2, n))
		&& find_index(stack2, n))
		idx = stack2.len - find_index(stack2, n);
	return (idx);
}

ssize_t	case_rr_r(t_stack stack1, t_stack stack2, int n)
{
	ssize_t	idx;

	idx = 0;
	if (!ft_strcmp(stack1.name, "a"))
	{
		if (find_index_a(stack1, n))
			idx = stack1.len - find_index_a(stack1, n);
		idx = find_index(stack2, n) + idx;
	}
	else if (!ft_strcmp(stack1.name, "b"))
	{
		if (find_index(stack2, n))
			idx = stack2.len - find_index(stack2, n);
		idx = find_index_b(stack1, n) + idx;
	}
	return (idx);
}

ssize_t	case_r_rr(t_stack stack1, t_stack stack2, int n)
{
	ssize_t	idx;

	idx = 0;
	if (!ft_strcmp(stack1.name, "a"))
	{
		if (find_index(stack2, n))
			idx = stack2.len - find_index(stack2, n);
		idx = find_index_a(stack1, n) + idx;
	}
	else if (!ft_strcmp(stack1.name, "b"))
	{
		if (find_index_b(stack1, n))
			idx = stack1.len - find_index_b(stack1, n);
		idx = find_index(stack2, n) + idx;
	}
	return (idx);
}

ssize_t	find_case(t_stack stack1, t_stack stack2)
{
	ssize_t	idx;
	t_list	*tmp;

	tmp = stack2.head;
	idx = case_rr_rr(stack1, stack2, *(int *)stack2.head->content);
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
