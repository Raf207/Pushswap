/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:17:22 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/29 14:59:27 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_ready(t_stack_node **stack, t_stack_node *cheap, char c)
{
	while (*stack != cheap)
	{
		if (c == 'a')
		{
			if (cheap->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c == 'b')
		{
			if (cheap->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	ft_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = ft_stack_cheapest(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		ft_rotate_a_b(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		ft_rev_rotate_a_b(a, b, cheap_node);
	ft_stack_ready(a, cheap_node, 'a');
	ft_stack_ready(b, cheap_node->target_node, 'b');
	pb(b, a);
}

void	ft_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_stack_ready(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	ft_sort_3(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = ft_stack_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

void	ft_sort_all(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && ft_stack_sorted(*a))
	{
		ft_init(*a, *b);
		ft_a_to_b(a, b);
	}
	ft_sort_3(a);
	while (*b)
	{
		ft_init_b(*a, *b);
		ft_b_to_a(a, b);
	}
	ft_index_median(*a);
	ft_min_top(a);
}
