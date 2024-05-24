/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:17:22 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/23 16:21:25 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = ft_stack_cheapest(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)

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

	len_a = ft_stack_len(a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !ft_stack_sorted*a))
		pb(b, a);
	while (len_a-- > 3 && ft_stack_sorted(*a))
	{
		ft_init(*a, *b);
		ft_a_to_b(a, b);
	}
}
