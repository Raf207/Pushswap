/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:40:07 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/23 15:29:53 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*next;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	top = (*stack);
	next = top->next;
	*stack = next;
	top->prev = next;
	top->next = next->next;
	next->prev = NULL;
	if (next->next)
		next->next->prev = top;
	next->next = top;
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

// int main()
// {
// 	t_stack_node	*a;
// 	t_stack_node	*test1;
// 	t_stack_node	*test2;

// 	a = NULL;
// 	ft_stack_append(&a, 10);
// 	ft_stack_append(&a, 15);
// 	ft_stack_append(&a, 20);
// 	ft_stack_append(&a, 25);
// 	test1 = a;
// 	test2 = a;
// 	while (test1)
// 	{
// 		printf("nb : %d\n", test1->nb);
// 		test1 = test1->next;
// 	}
// 	sa(&a);
// 	printf("test\n");
// 	test2 = a;
// 	while (test2)
// 	{
// 		printf("nb : %d\n", test2->nb);
// 		test2 = test2->next;
// 	}
// }