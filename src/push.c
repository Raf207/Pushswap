/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:31:58 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/21 21:52:51 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node;

	if (!src || !(*src))
		return ;
	node = *src;
	if ((*src)->next)
		(*src)->next->prev = NULL;
	(*src) = (*src)->next;
	if (!(*dst))
	{
		(*dst) = node;
		node->next = NULL;
	}
	{
		node->next = (*dst);
		(*dst)->prev = node;
		(*dst) = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	ft_push(a, b);
	ft_putstr("pb\n");
}
