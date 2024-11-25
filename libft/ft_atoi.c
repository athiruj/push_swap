/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:27 by athi              #+#    #+#             */
/*   Updated: 2024/11/12 17:38:02 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	short	m;
	int		tmp;

	m = 1;
	tmp = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			m *= -1;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
		tmp = tmp * 10 + (*str++ - '0');
	return (tmp * m);
}
