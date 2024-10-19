/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_initial_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:05:36 by atkaewse          #+#    #+#             */
/*   Updated: 2024/10/20 05:33:06 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*build_stack(int argc, char *argv[])
{
	t_list	*lst;
	t_list	*tmp_lst;
	char	**tmp_arr;
	size_t	i;

	if (argc < 2)
		return (NULL);
	lst = NULL;
	while (*++argv)
	{
		tmp_arr = ft_split(*argv, ' ');
		i = 0;
		while (tmp_arr[i])
		{
			if (!lst)
				lst = ft_lstnew(tmp_arr[i++]);
			else
			{
				tmp_lst = ft_lstnew(tmp_arr[i++]);
				ft_lstadd_back(&lst, tmp_lst);
			}
		}
		free(tmp_arr);
	}
	return (lst);
}

// t_list	*initial_stack(t_push_swap push_swap, int argc, char *argv[]);
// {
	
// }