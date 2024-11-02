/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:10 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 22:24:24 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, t_list **cmds)
{
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	if (stack->len == 2)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		stack->head->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp = stack->head;
		before_tail(tmp)->next = tmp;
		stack->head = stack->tail;
		stack->head->next = tmp->next;
		stack->tail = tmp;
		stack->tail->next = NULL;
	}
	if (*(char *)stack->name == 'a')
		add_cmd(cmds, "ra");
	else if (*(char *)stack->name == 'b')
		add_cmd(cmds, "rb");
}
