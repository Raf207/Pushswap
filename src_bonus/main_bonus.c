/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:24:48 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/09 15:23:12 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_split(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_splitt(av[1], ' ');
	ft_stack_init(&a, av + 1);
	ft_check_inst(&a, &b);
	if (ac == 2)
		ft_free_split(av);
	if (ft_stack_sorted(a) && ft_stack_len(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stack_free(&a);
	ft_stack_free(&b);
}
