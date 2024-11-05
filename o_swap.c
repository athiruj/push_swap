/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:03 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 13:53:24 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_swap(t_stack *stack_a, t_stack *stack_b, t_bool	cmd)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a, False);
	swap(stack_b, False);
	if (cmd)
		print_cmd(NULL, "ss");
}

void	swap(t_stack *stack, t_bool	cmd)
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
	if (cmd)
		print_cmd(stack, "s");
}
