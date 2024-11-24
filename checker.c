/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:26:49 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/25 01:05:43 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

t_bool	is_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "sa")
		&& ft_strcmp(cmd, "sb")
		&& ft_strcmp(cmd, "ss")
		&& ft_strcmp(cmd, "pa")
		&& ft_strcmp(cmd, "pb")
		&& ft_strcmp(cmd, "ra")
		&& ft_strcmp(cmd, "rb")
		&& ft_strcmp(cmd, "rr")
		&& ft_strcmp(cmd, "rra")
		&& ft_strcmp(cmd, "rrb")
		&& ft_strcmp(cmd, "rrr"))
	{
		return (False);
	}
	return (True);
}

t_bool	do_cmd(t_push_swap *push_swap, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		swap(push_swap->stack_a, NULL);
	else if (!ft_strcmp(cmd, "sb"))
		swap(push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "ss"))
		s_swap(push_swap->stack_a, push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "pa"))
		push(push_swap->stack_b, push_swap->stack_a, NULL);
	else if (!ft_strcmp(cmd, "pb"))
		push(push_swap->stack_a, push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "ra"))
		rotate(push_swap->stack_a, NULL);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "rr"))
		r_rotate(push_swap->stack_a, push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(push_swap->stack_a, NULL);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(push_swap->stack_b, NULL);
	else if (!ft_strcmp(cmd, "rrr"))
		r_reverse_rotate(push_swap->stack_a, push_swap->stack_b, NULL);
	else
		return (False);
	return (True);
}

// void print_stack(t_stack *stack)
// {
// 	while (stack->head)
// 	{
// 		printf("%d\n", *(int *)stack->head->content);
// 		stack->head = stack->head->next;
// 	}
// 	printf("\n");
// }

t_bool	sort_cmds(t_push_swap *push_swap)
{
	t_list	*tmp;

	tmp = push_swap->cmds;
	while (tmp)
	{
		if (!do_cmd(push_swap, tmp->content))
			return (False);
		tmp = tmp->next;
	}
	return (True);
}

t_bool	initial_cmd(t_list **cmds)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		if (tmp[0] && !is_cmd(tmp))
		{
			ft_putstr_fd("Error\n", 2);
			return (False);
		}
		if (tmp[0])
			add_cmd(cmds, tmp);
		else
			free(tmp);
		tmp = get_next_line(0);
	}
	return (True);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (1);
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (1);
	if (!initial_push_swap(push_swap, argv))
	{
		free(push_swap);
		return (1);
	}
	if (!initial_cmd(&push_swap->cmds))
	{
		free(push_swap);
		return (1);
	}
	if (sort_cmds(push_swap) && is_sorted(push_swap->stack_a->head))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_children(push_swap);
	free(push_swap);
	return (0);
}
