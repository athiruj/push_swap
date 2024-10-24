/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_input_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:26:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/24 11:24:31 by atkaewse         ###   ########.fr       */
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
	char	*tmp;
	char	*tmp_content;

	while (stack)
	{
		// ! tmp_content = (char *)stack->content;
		// ! tmp = ft_itoa(ft_atoi((char *)stack->content));
		// ! if (!tmp)
		// ! 	return (True);
		// ! if (*tmp_content == '+')
		// ! 	tmp_content++;
		// ! printf("%s ", tmp_content);
		// ! if (ft_strcmp(tmp, tmp_content))
		// ! {
		// ! 	free(tmp);
		// ! 	return (True);
		// ! }
		// ! free(tmp);
		stack = stack->next;
	}
	return (False);
}

static t_bool	ft_issorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (False);
		stack = stack->next;
	}
	return (True);
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
