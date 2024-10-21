/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_input_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:26:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/21 18:13:24 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_bool	ft_isinteger(t_list *stack)
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

static t_bool	ft_isduplicate(t_list *stack)
{
	t_list	*tmp_stack;

	while (stack->next)
	{
		tmp_stack = stack->next;
		while (tmp_stack)
		{
			if (!ft_strcmp((char *)stack->content, (char *)tmp_stack->content))
				return (True);
			tmp_stack = tmp_stack->next;
		}
		stack = stack->next;
	}
	return (False);
}

static t_bool	ft_isoverflow(t_list *stack)
{
	int		*n;

	while (stack)
	{
		n = (int *)malloc(sizeof(int)); 
		*n = ft_atol((char *)stack->content);
		stack->content = n;
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	return (False);
}

static t_bool	ft_issorted(t_list *stack)
{
	return (False);
}

t_bool	input_handler(int argc, char *argv[])
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!build_stack(stack, argc, argv)
		|| !ft_isinteger(stack)
		|| ft_isduplicate(stack)
		|| ft_isoverflow(stack))
	{
		ft_putstr_fd("ERROR\n", 1);
		ft_lstfree(stack);
		return (False);
	}
	if (ft_issorted(stack) || ft_lstsize(stack) < 2)
	{
		ft_lstfree(stack);
		return (False);
	}
	ft_lstfree(stack);
	return (True);
}
