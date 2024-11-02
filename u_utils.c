/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:28:43 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/02 21:26:36 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_cmd(t_list	**lst, char *cmd)
{
	if (!(*lst)->content)
		(*lst)->content = cmd;
	else
		ft_lstadd_front(lst, ft_lstnew(cmd));
}
