/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:06 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 18:19:30 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	num;

	num = *(int *)stack->head->content;
	while (stack->head)
	{
		if (num > *(int *)stack->head->content)
			num = *(int *)stack->head->content;
		stack->head = stack->head->next;
	}
	return (num);
}

int	find_max(t_stack *stack)
{
	int	num;

	num = *(int *)stack->head->content;
	while (stack->head)
	{
		if (num < *(int *)stack->head->content)
			num = *(int *)stack->head->content;
		stack->head = stack->head->next;
	}
	return (num);
}

ssize_t	find_index(t_stack *stack, int num)
{
	ssize_t	idx;

	idx = 0;
	while (*(int *)stack->head->content != num)
	{
		stack->head = stack->head->next;
		idx++;
	}
	return (idx);
}

ssize_t	find_index_a(t_stack *stack, int num)
{
	ssize_t	idx;
	t_list	*tmp;

	idx = 1;
	if (num < *(int *)stack->head->content
		&& num > *(int *)stack->tail->content)
		idx = 0;
	else if (num > find_max(stack) || num < find_min(stack))
		idx = find_index(stack, find_min(stack));
	else
	{
		tmp = stack->head->next;
		while (num < *(int *)stack->head->content || num > *(int *)tmp->content)
		{
			stack->head = stack->head->next;
			tmp = stack->head->next;
			idx++;
		}
	}
	return (idx);
}

ssize_t	find_index_b(t_stack *stack, int num)
{
	ssize_t	idx;
	t_list	*tmp;

	idx = 1;
	if (num < *(int *)stack->head->content
		&& num > *(int *)stack->tail->content)
		idx = 0;
	else if (num > find_max(stack) || num < find_min(stack))
		idx = find_index(stack, find_max(stack));
	else
	{
		tmp = stack->head->next;
		while (num > *(int *)stack->head->content || num < *(int *)tmp->content)
		{
			stack->head = stack->head->next;
			tmp = stack->head->next;
			idx++;
		}
	}
	return (idx);
}

