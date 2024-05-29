/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:37:16 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/29 13:08:30 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

int	main (int ac, char **av)
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
	if (!ft_stack_sorted(a))
	{
		if(ft_stack_len(a) == 2)
			sa(a);
		else if (ft_stack_len(a) == 3)
			ft_sort_3(&a);
		else
			ft_sort_all(&a, *b);
	}
	if (ac == 2)
		ft_free_split(av);
}