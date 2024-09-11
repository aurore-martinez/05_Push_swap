/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:58:40 by aumartin          #+#    #+#             */
/*   Updated: 2024/09/11 10:45:15 by aumartin         ###   ########.fr       */
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
void	move_min_to_top(t_stack *a, int min_index);

/* Prototypes fonctions stack */
void	init_stack(t_stack *stack, int capacity);
void	fill_stack(t_stack *stack, int argc, char **argv);
void	print_stack(t_stack *a, t_stack *b);
void	setup_stack(t_stack *a, t_stack *b, int ac, char **processed_args);
void	cleanup_stack(t_stack *a, t_stack *b, char **processed_args);

/* Prototypes fonctions error_management */
int		validate_input(int ac, char **av);
int		check_duplicates(int *arr, int size);
int		check_int_limits(char *str);
void	print_error_and_exit(void);

/* Prototypes fonctions utils */
int		contains_negative(t_stack *a);
void	free_split_args(char **split_args);
char	**process_arguments(int *argc, char **argv);

/* Prototypes fonctions sort */
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	sort_10(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	algo_turc(t_stack *a, t_stack *b);

int		is_sorted(t_stack *stack);
int		find_max(t_stack *a);
int		find_max_bits(int num);
int		find_max_index(t_stack *b);
void	find_min(t_stack *a, int *min_value, int *min_index);
void	finalize_sort(t_stack *a);

/* Prototypes fonctions tests */
int		calculate_cost(t_stack *a, t_stack *b, int index);
void	push_cheapest_to_b(t_stack *a, t_stack *b);
void	move_max_to_top(t_stack *b);
void	reinsert_sorted_b_to_a(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b, int chunk_size);
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_end);
void	sort_large_stack(t_stack *a, t_stack *b);
void	finalize_sort(t_stack *a);

#endif
