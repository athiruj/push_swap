/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:26:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 15:43:53 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_number(t_list *stack)
{
	char	*str;

	while (stack)
	{
		str = (char *)stack->content;
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str++))
				return (False);
		}
		stack = stack->next;
	}
	return (True);
}

static t_bool	is_overflow(t_list *stack)
{
	long	tmp;
	int		*tmp_int;

	while (stack)
	{
		tmp = ft_atol((char *)stack->content);
		if (INT_MIN > tmp || tmp > INT_MAX
			|| ft_strlen((char *)stack->content) > 11)
			return (True);
		tmp_int = (int *)malloc(sizeof(int));
		*tmp_int = (int)tmp;
		free(stack->content);
		stack->content = tmp_int;
		stack = stack->next;
	}
	return (False);
}

static t_bool	is_duplicate(t_list *stack)
{
	t_list	*tmp_stack;

	while (stack->next)
	{
		tmp_stack = stack->next;
		while (tmp_stack)
		{
			if (*(int *)stack->content == *(int *)tmp_stack->content)
			{
				return (True);
			}
			tmp_stack = tmp_stack->next;
		}
		stack = stack->next;
	}
	return (False);
}

t_bool	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (False);
		stack = stack->next;
	}
	return (True);
}

t_bool	stack_checker(t_list *stack)
{
	if (!stack)
		return (False);
	if (!is_number(stack)
		|| is_overflow(stack)
		|| is_duplicate(stack))
	{
		ft_putstr_fd("ERROR\n", 1);
		return (False);
	}
	if (is_sorted(stack))
		return (False);
	return (True);
}
