/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:40:07 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/21 21:31:28 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_node **stack)
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
	ft_putstr("sa\n");
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr("ss\n");
}
