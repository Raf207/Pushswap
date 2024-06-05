/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:44:37 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/05 14:44:42 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_dup_error(t_stack_node **stack, long nb)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if ((int) current->nb == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_str_error(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n[i] == '+' || str_n[i] == '-' || ft_isdigit(str_n[i]))
		|| ((str_n[i] == '+' || str_n[i] == '-')
			&& !ft_isdigit(str_n[i + 1])))
		return (1);
	while (str_n[++i])
		if (!ft_isdigit(str_n[i]))
			return (1);
	return (0);
}

void	ft_invalid_input(t_stack_node **stack)
{
	ft_stack_free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
