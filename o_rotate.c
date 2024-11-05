/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:10 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 15:03:19 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *stack_a, t_stack *stack_b, t_list **cmds)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (cmds)
		add_cmd(cmds, ft_strdup("rr"));
}

void	rotate(t_stack *stack, t_list **cmds)
{
	if (stack->len < 2)
		return ;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = NULL;
	if (cmds)
		add_cmd(cmds, ft_strjoin("r", stack->name));
}
