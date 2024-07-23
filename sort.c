/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:20:22 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/17 17:17:22 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	// Affichage des éléments de la pile pour controle
	ft_printf("a->data[0] : %d\n", a->data[0]);
	ft_printf("a->data[1] : %d\n", a->data[1]);
	ft_printf("a->data[2] : %d\n", a->data[2]); */

int	is_sorted(t_stack *stack)
{
	int	sorted;
	int	i;

	sorted = 1;
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
		{
			sorted = 0;
			break ;
		}
		i++;
	}
	return (sorted);
}

void	sort_2(t_stack *a)
{
	if (a->size != 2)
		return ;
	if (a->data[0] > a->data[1])
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	max_value;

	if (a->size != 3)
		return ;
	max_value = find_max(a);
	if (is_sorted(a))
		return ;
	if (a->data[a->size - 3] == max_value)
		ra(a);
	else if (a->data[a->size - 2] == max_value)
		rra(a);
	if (a->data[a->size - 3] > a->data[a->size - 2])
		sa(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_value;
	int	min_index;
	int	i;

	while (a->size > 3)
	{
		min_value = a->data[0];
		min_index = 0;
		i = 1;
		while (i < a->size)
		{
			if (a->data[i] < min_value)
			{
				min_value = a->data[i];
				min_index = i;
			}
			i++;
		}
		if (min_index == 0)
			pb(a, b);
		else if (min_index == a->size - 1)
		{
			rra(a);
			pb(a, b);
		}
		else
		{
			if (min_index <= a->size / 2)
				while (min_index-- > 0)
					ra(a);
			else
				while (min_index++ < a->size)
					rra(a);
			pb(a, b);
		}
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_num = find_max(a);
	max_bits = find_max_bits(max_num);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a->size;
		while (j < size)
		{
			if (((a->data[0] >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
