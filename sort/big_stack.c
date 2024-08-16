/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:43:08 by aumartin          #+#    #+#             */
/*   Updated: 2024/08/16 15:44:34 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 	// Affichage des éléments de la pile pour controle
	ft_printf("a->data[0] : %d\n", a->data[0]);
	ft_printf("a->data[1] : %d\n", a->data[1]);
	ft_printf("a->data[2] : %d\n", a->data[2]); */

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


void	sort_big_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 100)
	{
		if (contains_negative (a))
			quicksort(a, b);
		else
			radix_sort(a, b);
	}
	else if (a->size <= 500)
	{
		if (contains_negative (a))
			quicksort(a, b);
		else
			radix_sort(a, b);
	}
	else
	{
		if (contains_negative (a))
			quicksort(a, b);
		else
			radix_sort(a, b);
	}
}
