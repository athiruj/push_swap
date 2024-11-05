/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:08 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 14:54:36 by atkaewse         ###   ########.fr       */
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
	if (cmds)
		add_cmd(cmds, ft_strjoin("p", to_stack->name));
	to_stack->len++;
	from_stack->len--;
}
