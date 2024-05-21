/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:03:00 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/21 22:07:07 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	last = ft_lstlast(*stack);
	last->next = (*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	(*stack) = last;
}
