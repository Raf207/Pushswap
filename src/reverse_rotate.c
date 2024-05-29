/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:03:00 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/29 13:35:21 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_stack_last(*stack);
	first = (*stack);
	last->next = first;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack) = last;
}

void	rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	ft_rev_rotate_a_b(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheap)
{
	while ((*b) != cheap->target_node && (*a) != cheap)
		rrr(a, b);
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
// 	rra(&a);
// 	printf("test\n");
// 	test2 = a;
// 	while (test2)
// 	{
// 		printf("nb : %d\n", test2->nb);
// 		test2 = test2->next;
// 	}
// }
