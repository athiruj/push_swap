/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:28:43 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/24 21:46:00 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_cmd(t_list	**lst, char *cmd)
{
	if (!(*lst)->content)
		(*lst)->content = cmd;
	else
		ft_lstadd_back(lst, ft_lstnew(cmd));
}

t_list	*before_tail(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	print_cmds(t_list *cmds)
{
	t_list	*tmp;

	if (!cmds->content)
		return ;
	tmp = cmds;
	while (tmp)
	{
		ft_putstr_fd((char *)tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
