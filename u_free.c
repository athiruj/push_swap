/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:22:33 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 21:29:43 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	free_children(t_push_swap *push_swap)
{
	if (!push_swap)
		return (True);
	if (push_swap->stack_a)
		free_stack(push_swap->stack_a);
	if (push_swap->stack_b)
		free_stack(push_swap->stack_b);
	if (push_swap->cmds)
		ft_lstfree(push_swap->cmds);
	return (True);
}

t_bool	free_fail_children(t_push_swap *push_swap)
{
	if (!push_swap)
		return (True);
	if (push_swap->stack_a)
		free(push_swap->stack_a);
	if (push_swap->stack_b)
		free(push_swap->stack_b);
	if (push_swap->cmds)
		free(push_swap->cmds);
	return (True);
}

t_bool	free_stack(t_stack *stack)
{
	t_list	*tmp;

	if (!stack)
		return (True);
	while (stack->head)
	{
		tmp = stack->head->next;
		if (stack->head->content)
			free(stack->head->content);
		free(stack->head);
		stack->head = tmp;
	}
	free(stack);
	return (True);
}

t_bool	free_arr(char **arr)
{
	if (!arr)
		return (True);
	while (*arr)
		free(*arr++);
	free(arr);
	return (True);
}
