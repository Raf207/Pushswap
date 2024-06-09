/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:41:18 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/09 15:41:19 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_index_median(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		++i;
		stack = stack->next;
	}
}

void	ft_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curren_b;
	t_stack_node	*target;
	long			closest_small_nb;

	while (a)
	{
		closest_small_nb = LONG_MIN;
		curren_b = b;
		while (curren_b)
		{
			if (curren_b->nb < a->nb
				&& curren_b->nb > closest_small_nb)
			{
				closest_small_nb = curren_b->nb;
				target = curren_b;
			}
			curren_b = curren_b->next;
		}
		if (closest_small_nb == LONG_MIN)
			a->target_node = ft_stack_biggest(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	ft_swap_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->cost += a->target_node->index;
		else
			a->cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	ft_find_cheapest(t_stack_node *stack)
{
	long			cheap_cost;
	t_stack_node	*cheap_node;

	cheap_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheap_cost)
		{
			cheap_cost = stack->cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = true;
}

void	ft_init(t_stack_node *a, t_stack_node *b)
{
	ft_index_median(a);
	ft_index_median(b);
	ft_target_a(a, b);
	ft_swap_cost(a, b);
	ft_find_cheapest(a);
}
