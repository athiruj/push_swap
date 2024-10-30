/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:11 by athi              #+#    #+#             */
/*   Updated: 2024/10/30 12:54:13 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	t_push_swap	*push_swap;

// 	if (argc < 2)
// 		return (0);
// 	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
// 	if (!push_swap)
// 		return (0);
// 	if (!initial_push_swap(push_swap, argc, argv))
// 	{
// 		free(push_swap);
// 		return (0);
// 	}
// 	sort_push_swap(push_swap);
// 	optimize_cmd(push_swap->cmds);
// 	print_cmds(push_swap->cmds);
// 	free_push_swap(push_swap);
// 	return (1);
// }

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (0);
	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (0);
	if (!initial_push_swap(push_swap, argc, argv))
	{
		free(push_swap);
		return (0);
	}
	free_children(push_swap);
	free(push_swap);
	printf("OK\n");
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	// t_push_swap	*push_swap;
// 	// argc = 3;
// 	// argv[1] = "2";
// 	// argv[2] = "3";
// 	// argv[3] = 0;
// 	// argv[3] = "5";
// 	// argv[4] = "3";
// 	// argv[5] = "1";
// 	// argv[6] = "2";
// 	// argv[7] = 0;
// 	if (argc < 2)
// 		return (0);
// 	if (!input_handler(argc, argv))
// 		return (0);
// 	printf("OK");
// 	return (1);
// }


// int main ()
// {
// 	printf("%d", atoi("+"));
// }
// 	char *maxlong = "9223372036854775807";
// 	char *minlong = "-9223372036854775808";
// 	char *maxint = "2147483647";
// 	char *minint = "-2147483648";
// 	printf("%d \n", ft_atoi(minint));
// 	printf("%d \n", ft_atoi(maxint));
// 	printf("%ld \n", ft_atol(minlong));
// 	printf("%ld \n", ft_atol(maxlong));
// }