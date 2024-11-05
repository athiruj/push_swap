/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:03 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 15:04:35 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_swap(t_stack *stack_a, t_stack *stack_b, t_list **cmds)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (cmds)
		add_cmd(cmds, ft_strdup("ss"));
}

void	swap(t_stack *stack, t_list **cmds)
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (stack->len < 2)
		return ;
	if (stack->len == 2)
	{
		tmp = stack->head;
		stack->head = stack->tail;
		stack->head->next = tmp;
		stack->tail = tmp;
		stack->tail->next = NULL;
	}
	else
	{
		tmp = stack->head;
		tmp_next = stack->head->next->next;
		stack->head = stack->head->next;
		stack->head->next = tmp;
		tmp->next = tmp_next;
	}
	if (cmds)
		add_cmd(cmds, ft_strjoin("s", stack->name));
}
