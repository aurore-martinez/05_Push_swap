/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:19:27 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/20 10:28:46 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int capacity)
{
	stack->data = (int *)malloc(capacity * sizeof(int));
	if (!stack->data)
		print_error_and_exit();
	stack->size = 0;
	stack->capacity = capacity;
	stack->operation_count = 0;
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		stack->data[i] = ft_atoi(argv[i]);
		i++;
	}
	stack->size = argc;
}

void	print_stack(t_stack *a, t_stack *b)
{
	int	max_size;
	int	i;

	if (a->size > b->size)
		max_size = a->size;
	else
		max_size = b->size;
	i = 0;
	while (i < max_size)
	{
		if (i < a->size)
			ft_printf("%d ", a->data[i]);
		else
			ft_printf("_ ");
		if (i < b->size)
			ft_printf("%d ", b->data[i]);
		else
			ft_printf("_ ");
		i++;
		ft_printf("\n");
	}
	ft_printf("a b\n");
	ft_printf("----------------------------------------\n");
}
