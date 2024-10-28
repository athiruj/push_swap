/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:22:33 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/28 16:02:52 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	free_push_swap_children(t_push_swap *push_swap)
{
	if (!push_swap)
		return (False);
	free_stack(push_swap->stack_a);
	free_stack(push_swap->stack_b);
	ft_lstfree(push_swap->cmds);
	return (True);
}

t_bool	free_fail_push_swap_children(t_push_swap *push_swap)
{
	if (!push_swap)
		return (False);
	free(push_swap->stack_a);
	free(push_swap->stack_b);
	free(push_swap->cmds);
	return (True);
}

t_bool	free_stack(t_stack *stack)
{
	if (!stack)
		return (True);
	ft_lstfree(stack->head);
	free(stack);
	return (True);
}
