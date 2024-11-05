/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:28:43 by atkaewse          #+#    #+#             */
/*   Updated: 2024/11/05 14:27:11 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_stack	*stack, char *cmd)
{
	if (cmd)
		write(1, cmd, ft_strlen(cmd));
	if (stack)
		write(1, stack->name, ft_strlen(stack->name));
	if (cmd || stack)
		write(1, "\n\0", ft_strlen(cmd));
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