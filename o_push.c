/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:08 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 13:49:52 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from_stack, t_stack *to_stack, t_bool cmd)
{
	t_list	*tmp;

	if (!from_stack)
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
	to_stack->len++;
	from_stack->len--;
	if (cmd)
		print_cmd(to_stack, "p");
}
