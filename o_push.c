/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:08 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 21:39:26 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from_stack, t_stack *to_stack, t_list **cmds)
{
	t_list	*tmp;

	if (!from_stack->head)
		return ;
	if (!to_stack->head)
	{
		to_stack->head = from_stack->head;
		to_stack->tail = from_stack->head;
		from_stack->head = from_stack->head->next;
		to_stack->head->next = NULL;
	}
	else
	{
		tmp = to_stack->head;
		to_stack->head = from_stack->head;
		from_stack->head = from_stack->head->next;
		to_stack->head->next = tmp;
	}
	if (*(char *)to_stack->name == 'a')
		add_cmd(cmds, "pa");
	else if (*(char *)to_stack->name == 'b')
		add_cmd(cmds, "pb");
	to_stack->len++;
	from_stack->len--;
}
