/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:31:09 by aumartin          #+#    #+#             */
/*   Updated: 2025/02/24 16:07:09 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_min_to_top(t_stack *a, int min_index)
{
	if (min_index <= a->size / 2)
		while (min_index-- > 0)
			ra(a);
	else
		while (min_index++ < a->size)
			rra(a);
}
/* Trouve l'index du plus petit élément
Déplace le minimum en tête */

void	min_to_top_a(t_stack *a)
{
	int	min_index;

	find_min(a, &min_index);
	if (min_index <= a->size / 2)
	{
		while (min_index-- > 0)
			ra(a);
	}
	else
	{
		while (min_index++ < a->size)
			rra(a);
	}
}

/* Déplace les n plus petits éléments de a vers b */
void	move_n_min_to_b(t_stack *a, t_stack *b, int n)
{
	while (n-- > 0)
	{
		min_to_top_a(a);
		pb(a, b);
	}
}
