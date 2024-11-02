/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:03 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 23:42:12 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	if (*(char *)stack->name == 'a')
		add_cmd(cmds, "sa");
	else if (*(char *)stack->name == 'b')
		add_cmd(cmds, "sb");
}
