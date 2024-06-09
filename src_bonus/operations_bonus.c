/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:52 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/09 15:42:11 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate(t_stack_node **stack)
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

void	ft_rotate(t_stack_node **stack)
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

void	ft_push(t_stack_node **src, t_stack_node **dst)
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
