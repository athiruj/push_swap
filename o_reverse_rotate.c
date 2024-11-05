/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:15 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 13:52:13 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_bool cmd)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a, False);
	reverse_rotate(stack_b, False);
	if (cmd)
		print_cmd(NULL, "rrr");
}

void	reverse_rotate(t_stack *stack, t_bool cmd)
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
	if (cmd)
		print_cmd(stack, "rr");
}
