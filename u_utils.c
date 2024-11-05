/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:28:43 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 18:03:30 by atkaewse         ###   ########.fr       */
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
		write(1, (char *)tmp->content, ft_strlen((char *)tmp->content));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}