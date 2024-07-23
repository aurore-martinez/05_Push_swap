/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:58:40 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/18 14:26:18 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft/libft.h"
# include "Libft/ft_printf/ft_printf.h"

/* structure stack */
typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
	int	operation_count;
}	t_stack;

/* Prototypes fonctions moves */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Prototypes fonctions stack */
void	init_stack(t_stack *stack, int capacity);
void	fill_stack(t_stack *stack, int argc, char **argv);
void	print_stack(t_stack *a, t_stack *b);

/* Prototypes fonctions error_management */
int		validate_input(int ac, char **av);
int		check_duplicates(int *arr, int size);
int		check_int_limits(char *str);
void	print_error_and_exit(void);

/* Prototypes fonctions utils */
long	ft_atol(const char *str);
int		find_max(t_stack *a);
int		find_max_bits(int num);

/* Prototypes fonctions sort */
int		is_sorted(t_stack *stack);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
