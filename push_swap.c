/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:14:11 by athi              #+#    #+#             */
/*   Updated: 2024/11/05 14:28:43 by atkaewse         ###   ########.fr       */
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
void print_lst(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
void print_stack(t_stack *stack)
{
	t_list *tmp;
	
	tmp = stack->head;
	while (tmp)
	{
		printf("%d ", *((int *)tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_push_swap	*push_swap;

	// argc = 4;
	// argv[1] = "4"; 
	// argv[2] = "2"; 
	// argv[3] = "5";
	// argv[4] = 0; 
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
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// printf("------\n");
	rotate(push_swap->stack_a, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// print_lst(push_swap->cmds);
	// printf("------\n");
	push(push_swap->stack_a, push_swap->stack_b, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// printf("------\n");
	push(push_swap->stack_a, push_swap->stack_b, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// print_lst(push_swap->cmds);
	// printf("------\n");
	reverse_rotate(push_swap->stack_a, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// print_lst(push_swap->cmds);
	// printf("------\n");
	swap(push_swap->stack_a, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// printf("------\n");
	s_swap(push_swap->stack_a, push_swap->stack_b, True);
	// print_stack(push_swap->stack_a);
	// print_stack(push_swap->stack_b);
	// print_lst(push_swap->cmds);
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