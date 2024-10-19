/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:11 by athi              #+#    #+#             */
/*   Updated: 2024/10/20 05:33:43 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	// t_push_swap	*push_swap;
	// argc = 3;
	// argv[1] = "1 2 3 4 1232";
	// argv[2] = "5 6 7 8 321321";
	// argv[3] = 0;
	// argv[3] = "5";
	// argv[4] = "3";
	// argv[5] = "1";
	// argv[6] = "2";
	// argv[7] = 0;

	if (!input_handler(argc, argv))
		return (0);
	return (1);
}

// int main ()
// {
// 	char *maxlong = "9223372036854775807";
// 	char *minlong = "-9223372036854775808";
// 	char *maxint = "2147483647";
// 	char *minint = "-2147483648";
// 	printf("%d \n", ft_atoi(minint));
// 	printf("%d \n", ft_atoi(maxint));
// 	printf("%ld \n", ft_atol(minlong));
// 	printf("%ld \n", ft_atol(maxlong));
// }