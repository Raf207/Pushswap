/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:25:24 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/05 18:13:26 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

char			**ft_splitt(char const *s, char c);
void			ft_invalid_input(t_stack_node **stack);
int				ft_str_error(char *str_n);
int				ft_dup_error(t_stack_node **stack, long nb);
void			ft_stack_free(t_stack_node **a);
void			ft_stack_append(t_stack_node **stack, int nb);
void			ft_stack_init(t_stack_node **stack, char **av);
int				ft_stack_sorted(t_stack_node *stack);
int				ft_stack_len(t_stack_node *stack);
t_stack_node	*ft_stack_last(t_stack_node *stack);
void			ft_reverse_rotate(t_stack_node **stack);
void			ft_rotate(t_stack_node **stack);
void			ft_push(t_stack_node **src, t_stack_node **dst);
void			ft_swap(t_stack_node **stack);
int				ft_instr(t_stack_node **a, t_stack_node **b, char *operation);
void			ft_check_inst(t_stack_node **a, t_stack_node **b);
#endif