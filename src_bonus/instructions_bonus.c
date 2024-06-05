/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:56:29 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/05 19:28:02 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_instr(t_stack_node **a, t_stack_node **b, char *operation)
{
	if (ft_strncmp(operation, "pa", 5) == 0)
		return (ft_push(b, a), 1);
	else if (ft_strncmp(operation, "pb", 5) == 0)
		return (ft_push(a, b), 1);
	else if (ft_strncmp(operation, "sa", 5) == 0)
		return (ft_swap(a), 1);
	else if (ft_strncmp(operation, "sb", 5) == 0)
		return (ft_swap(b), 1);
	else if (ft_strncmp(operation, "ss", 5) == 0)
		return (ft_swap(a), ft_swap(b), 1);
	else if (ft_strncmp(operation, "ra", 5) == 0)
		return (ft_rotate(a), 1);
	else if (ft_strncmp(operation, "rb", 5) == 0)
		return (ft_rotate(b), 1);
	else if (ft_strncmp(operation, "rr", 5) == 0)
		return (ft_rotate(a), ft_rotate(b), 1);
	else if (ft_strncmp(operation, "rra", 5) == 0)
		return (ft_reverse_rotate(a), 1);
	else if (ft_strncmp(operation, "rrb", 5) == 0)
		return (ft_reverse_rotate(b), 1);
	else if (ft_strncmp(operation, "rrr", 5) == 0)
		return (ft_reverse_rotate(a), ft_reverse_rotate(b), 1);
	else
		return (0);
}

void	ft_check_inst(t_stack_node **a, t_stack_node **b)
{
	char	*instr;

	instr = get_next_line(0);
	while (instr != NULL)
	{
		if (!ft_instr(a, b, instr))
		{
			ft_stack_free(b);
			ft_invalid_input(a);
		}
		free(instr);
		instr = get_next_line(0);
	}
}
