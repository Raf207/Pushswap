/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:31:58 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/23 15:29:34 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node;

	if (!src || !(*src))
		return ;
	node = *src;
	(*src) = (*src)->next;
	if ((*src))
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!(*dst))
	{
		node->next = NULL;
		(*dst) = node;
	}
	else
	{
		node->next = (*dst);
		(*dst)->prev = node;
		(*dst) = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(b, a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	ft_push(a, b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

// int main()
// {
// 	t_stack_node	*a;
// 	t_stack_node	*test1;
// 	t_stack_node	*test2;
// 	t_stack_node	*testb;
// 	t_stack_node	*testb2;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	ft_stack_append(&a, 10);
// 	ft_stack_append(&a, 15);
// 	ft_stack_append(&a, 20);
// 	ft_stack_append(&a, 25);
// 	test1 = a;
// 	testb = b;
// 	while (test1)
// 	{
// 		printf("nba1 : %d\n", test1->nb);
// 		test1 = test1->next;
// 	}
// 	printf("--------------------------------------------\n");
// 	while (testb)
// 	{
// 		printf("nbb1 : %d\n", testb->nb);
// 		testb = testb->next;
// 	}
// 	pb(&b, &a);
// 	printf("==================================================\n");
// 	test2 = a;
// 	testb2 = b;
// 	while (test2)
// 	{
// 		printf("nba2 : %d\n", test2->nb);
// 		test2 = test2->next;
// 		printf("test ptr test2: %p\n", test2);
// 	}
// 	printf("--------------------------------------------\n");
// 	while (b)
// 	{
// 		printf("nbb2 : %d\n", b->nb);
// 		b = b->next;
// 	}
// }
