/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:15 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 15:03:19 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_list **cmds)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (cmds)
		add_cmd(cmds, ft_strdup("rrr"));
}

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
	if (cmds)
		add_cmd(cmds, ft_strjoin("rr", stack->name));
}
