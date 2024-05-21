/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:54:51 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/21 22:02:17 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	last = ft_lstlast(*stack);
	last->next = (*stack);
	(*stack)->prev = last;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr("rr\n");
}
