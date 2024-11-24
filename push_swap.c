/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:11 by athi              #+#    #+#             */
/*   Updated: 2024/11/24 21:21:25 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	while (stack->head)
// 	{
// 		printf("s %d\n", *(int *)stack->head->content);
// 		stack->head = stack->head->next;
// 	}
// 	printf("\n");
// }

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (0);
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (0);
	if (!initial_push_swap(push_swap, argv))
	{
		free(push_swap);
		return (0);
	}
	if (!is_sorted(push_swap->stack_a->head) && sort_push_swap(push_swap))
		print_cmds(push_swap->cmds);
	free_children(push_swap);
	free(push_swap);
	return (0);
}
