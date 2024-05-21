/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:42 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/21 22:02:37 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/include/libft.h"

typedef struct s_stack_node
{
	int					nb;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**ft_splitt(char const *s, char c);
void	ft_invalid_input(t_stack_node **stack);
int		ft_str_error(char *str_n);
void	ft_stack_free(t_stack_node **a);
void	ft_stack_append(t_stack_node **stack, int nb);
void	ft_stack_init(t_stack_node **stack, char **av);
int		ft_stack_sorted(t_stack_node *stack);
int		ft_stack_len(t_stack_node *stack);
void	ft_swap(t_stack_node **stack);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
void	ss(t_stack_node **a, t_stack_node **b);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rb(t_stack_node **b);
void	ra(t_stack_node **a);

#endif