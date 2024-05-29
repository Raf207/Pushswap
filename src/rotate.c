/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:54:51 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/29 13:32:13 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_stack_last(*stack);
	first = (*stack);
	last->next = first;
	first->prev = last;
	(*stack) = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	ft_rotate_a_b(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while ((*b) != cheap->target_node && (*a) != cheap)
		rr(a, b);
	ft_index_median((*a));
	ft_index_median((*b));
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
// 	ra(&a);
// 	printf("test\n");
// 	test2 = a;
// 	while (test2)
// 	{
// 		printf("nb : %d\n", test2->nb);
// 		test2 = test2->next;
// 	}
// }
