/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:41:10 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/09 15:41:11 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*ft_stack_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack_node	*ft_stack_biggest(t_stack_node *stack)
{
	t_stack_node	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	stack = stack->next;
	while (stack)
	{
		if (biggest->nb < stack->nb)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack_node	*ft_stack_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	stack = stack->next;
	while (stack)
	{
		if (smallest->nb > stack->nb)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack_node	*ft_stack_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
