/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:56 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/23 13:57:42 by rafnasci         ###   ########.fr       */
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

void	ft_stack_free(t_stack_node **a)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
}

void	ft_stack_append(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->nb = nb;
	node->next = NULL;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_stack_last((*stack));
		last_node->next = node;
		node->prev = last_node;
	}
}

int	ft_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->next->nb < stack->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
