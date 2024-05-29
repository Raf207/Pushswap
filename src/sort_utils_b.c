/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:27 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/29 14:21:17 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			closest_biggest_nb;

	while (b)
	{
		closest_biggest_nb = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb
				&& current_a->nb < closest_biggest_nb)
			{
				closest_biggest_nb = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_biggest_nb == LONG_MAX)
			b->target_node = ft_stack_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	ft_init_b(t_stack_node *a, t_stack_node *b)
{
	ft_index_median(a);
	ft_index_median(b);
	ft_target_b(a, b);
}

void	ft_min_top(t_stack_node **a)
{
	while ((*a)->nb != ft_stack_smallest(*a)->nb)
	{
		if (ft_stack_smallest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
