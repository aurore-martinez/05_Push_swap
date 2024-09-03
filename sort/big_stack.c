/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:43:08 by aumartin          #+#    #+#             */
/*   Updated: 2024/09/03 14:06:47 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 	// Affichage des éléments de la pile pour controle
	for (int i = 0; i < a->size; i++)
				ft_printf("a->data[%d] : %d\n", i, a->data[i]);
*/

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

void	algo_turc(t_stack *a, t_stack *b)
{
	int	max_index;

	// Pousser tous les éléments de a vers b
	while (a->size > 0)
		pb(a, b);

		// optimise pour calculer le meilleur value qui va dans la b (celui qui coute le moins cher)

	// Réinsérer les éléments de b vers a en triant
	while (b->size > 0)
	{
		max_index = find_max_index(b);
		// Mettre l'élément maximum au sommet de b
		if (max_index <= b->size / 2)
		{
			while (max_index-- > 0)
				rb(b);
		}
		else
		{
			max_index = b->size - max_index;
			while (max_index-- > 0)
				rrb(b);
		}
		pa(a, b); // Pousser l'élément maximum vers a
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 100)
	{
		if (contains_negative (a))
			algo_turc(a, b);
		else
			radix_sort(a, b);
	}
	else if (a->size <= 500)
	{
		if (contains_negative (a))
			algo_turc(a, b);
		else
			radix_sort(a, b);
	}
	else
	{
		if (contains_negative (a))
			algo_turc(a, b);
		else
			radix_sort(a, b);
	}
}
