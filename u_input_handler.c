/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_input_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:26:35 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/20 05:38:15 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_bool	ft_isalldigit(t_list *lst)
{
	return (True);
}

static t_bool	ft_isduplicate(t_list *lst)
{
	return (False);
}

static t_bool	ft_isoverflow(t_list *lst)
{
	return (False);
}

static t_bool	ft_issorted(t_list *lst)
{
	return (False);
}

t_bool	input_handler(int argc, char *argv[])
{
	t_list	*lst;

	if (argc < 2)
		return (False);
	lst = build_stack(argc, argv);
	if (!ft_isalldigit(lst) || ft_isduplicate(lst) || ft_isoverflow(lst))
	{
		ft_lstfree(lst);
		ft_putstr_fd("ERROR", 1);
		return (False);
	}
	if (ft_issorted(lst))
	{
		ft_lstfree(lst);
		return (False);
	}
	ft_lstfree(lst);
	return (True);
}
