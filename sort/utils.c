/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:45:16 by aumartin          #+#    #+#             */
/*   Updated: 2024/09/03 11:21:56 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/* Parcourt tous les éléments de la pile a pour trouver la valeur maximale. */

int	find_max(t_stack *a)
{
	int	max;
	int	i;

	max = a->data[0];
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] > max)
			max = a->data[i];
		i++;
	}
	return (max);
}
/* Calcule le nombre de bits nécessaires pour représenter un nombre donné
en utilisant des décalages binaires vers la droite (>>). Pour chaque décalage,
le nombre est divisé par 2, et le compteur de bits (bits) est incrémenté jusqu'à
ce que le nombre soit réduit à zéro. Cela nous donne le nombre de bits
nécessaires pour représenter le nombre en binaire. */

int	find_max_bits(int num)
{
	int	bits;

	bits = 0;
	while (num)
	{
		num >>= 1;
		bits++;
	}
	return (bits);
}

// Fonction pour trouver l'index du plus grand élément dans la pile b
int	find_max_index(t_stack *b)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
