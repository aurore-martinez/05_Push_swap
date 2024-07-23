/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:58:58 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/18 12:03:41 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
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
