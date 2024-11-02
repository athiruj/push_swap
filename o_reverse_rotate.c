/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:15 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 22:45:58 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, t_list **cmds)
{
	t_list	*tmp_before;

	if (stack->len < 2)
		return ;
	tmp_before = before_tail(stack->head);
	if (!tmp_before)
		return ;
	tmp_before->next = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp_before;
	if (*(char *)stack->name == 'a')
		add_cmd(cmds, "rra");
	else if (*(char *)stack->name == 'b')
		add_cmd(cmds, "rrb");
}
