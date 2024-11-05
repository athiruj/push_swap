/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:10 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 13:48:03 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *stack_a, t_stack *stack_b, t_bool cmd)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, False);
	rotate(stack_b, False);
	if (cmd)
		print_cmd(NULL, "rr");
}

void	rotate(t_stack *stack, t_bool	cmd)
{
	if (stack->len < 2)
		return ;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = NULL;
	if (cmd)
		print_cmd(stack, "r");
}
