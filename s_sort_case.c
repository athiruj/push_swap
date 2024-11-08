/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:47:03 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/08 18:27:14 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	r_r(t_stack *from_stack, t_stack *to_stack, t_list **cmds, int n)
{
	if (!ft_strcmp(from_stack->name, "a"))
	{
		while (*(int *)to_stack->head->content != n
			&& find_index_a(*from_stack, n) > 0)
			r_rotate(from_stack, to_stack, cmds);
		while (*(int *)to_stack->head->content != n)
			rotate(to_stack, cmds);
		while (find_index_a(*from_stack, n) > 0)
			rotate(from_stack, cmds);
	}
	else if (!ft_strcmp(from_stack->name, "b"))
	{
		while (*(int *)to_stack->head->content != n
			&& find_index_b(*from_stack, n) > 0)
			r_rotate(from_stack, to_stack, cmds);
		while (*(int *)to_stack->head->content != n)
			rotate(to_stack, cmds);
		while (find_index_b(*from_stack, n) > 0)
			rotate(from_stack, cmds);
	}
	push(to_stack, from_stack, cmds);
	return (-1);
}

ssize_t	rr_rr(t_stack *from_stack, t_stack *to_stack, t_list **cmds, int n)
{
	if (!ft_strcmp(from_stack->name, "a"))
	{
		while (*(int *)to_stack->head->content != n
			&& find_index_a(*from_stack, n) > 0)
			r_reverse_rotate(from_stack, to_stack, cmds);
		while (*(int *)to_stack->head->content != n)
			reverse_rotate(to_stack, cmds);
		while (find_index_a(*from_stack, n) > 0)
			reverse_rotate(from_stack, cmds);
	}
	else if (!ft_strcmp(from_stack->name, "b"))
	{
		while (*(int *)to_stack->head->content != n
			&& find_index_b(*from_stack, n) > 0)
			r_reverse_rotate(from_stack, to_stack, cmds);
		while (*(int *)to_stack->head->content != n)
			reverse_rotate(to_stack, cmds);
		while (find_index_b(*from_stack, n) > 0)
			reverse_rotate(from_stack, cmds);
	}
	push(to_stack, from_stack, cmds);
	return (-1);
}

ssize_t	rr_r(t_stack *from_stack, t_stack *to_stack, t_list **cmds, int n)
{
	if (!ft_strcmp(from_stack->name, "a"))
	{
		while (find_index_a(*from_stack, n) > 0)
			reverse_rotate(from_stack, cmds);
		while (*(int *)to_stack->head->content != n)
			rotate(to_stack, cmds);
	}
	else if (!ft_strcmp(from_stack->name, "b"))
	{
		while (*(int *)to_stack->head->content != n)
			reverse_rotate(to_stack, cmds);
		while (find_index_b(*from_stack, n) > 0)
			rotate(from_stack, cmds);
	}
	push(to_stack, from_stack, cmds);
	return (-1);
}

ssize_t	r_rr(t_stack *from_stack, t_stack *to_stack, t_list **cmds, int n)
{
	if (!ft_strcmp(from_stack->name, "a"))
	{
		while (find_index_a(*from_stack, n) > 0)
			rotate(from_stack, cmds);
		while (*(int *)from_stack->head->content != n)
			reverse_rotate(to_stack, cmds);
	}
	else if (!ft_strcmp(from_stack->name, "b"))
	{
		while (*(int *)to_stack->head->content != n)
			rotate(to_stack, cmds);
		while (find_index_b(*from_stack, n) > 0)
			reverse_rotate(from_stack, cmds);
	}
	push(to_stack, from_stack, cmds);
	return (-1);
}
