/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:11 by athi              #+#    #+#             */
/*   Updated: 2024/11/06 15:26:38 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		printf("%d ", *((int *)tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (0);
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (0);
	if (!initial_push_swap(push_swap, argc, argv))
	{
		free(push_swap);
		return (0);
	}
	if (sort_push_swap(push_swap))
		print_cmds(push_swap->cmds);
	print_stack(push_swap->stack_a);
	free_children(push_swap);
	free(push_swap);
	return (1);
}
