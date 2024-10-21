/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_initial_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:05:36 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/21 18:01:04 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	push_stack(t_list *stack, char *str)
{
	t_list	*tmp_stack;

	if (!stack->content)
		stack->content = str;
	else
	{
		tmp_stack = ft_lstnew(str);
		if (!tmp_stack)
			return (False);
		ft_lstadd_back(&stack, tmp_stack);
	}
	return (True);
}

t_bool	build_stack(t_list	*stack, int argc, char *argv[])
{
	char	**tmp_arr;
	size_t	i;

	while (*++argv)
	{
		tmp_arr = ft_split(*argv, ' ');
		if (!tmp_arr || !(tmp_arr[0]))
		{
			free(tmp_arr);
			return (False);
		}
		i = 0;
		while (tmp_arr[i])
		{
			if (!push_stack(stack, tmp_arr[i++]))
				return (False);
		}
		free(tmp_arr);
	}
	return (True);
}

// t_list	*initial_stack(t_push_swap push_swap, int argc, char *argv[]);
// {
// }