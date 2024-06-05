/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:39:39 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/05 19:14:51 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
		res = (res * 10) + (str[i++] - '0');
	return (sign * res);
}

void	ft_stack_init(t_stack_node **stack, char **av)
{
	long	nb;
	int		i;

	i = -1;
	while (av[++i])
	{
		if (ft_str_error(av[i]))
			ft_invalid_input(stack);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_invalid_input(stack);
		if (ft_dup_error(stack, nb))
			ft_invalid_input(stack);
		ft_stack_append(stack, (int)nb);
	}
}
