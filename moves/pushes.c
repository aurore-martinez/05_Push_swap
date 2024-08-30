/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:30:21 by aumartin          #+#    #+#             */
/*   Updated: 2024/08/30 15:40:05 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size < 1)
		return ;
	a->data[a->size] = b->data[0];
	a->size++;
	if (a->size > 1)
	{
		i = a->size - 1;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
	}
	i = 0;
	a->data[0] = b->data[0];
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->size--;
	ft_printf("pa\n");
	a->operation_count++;
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size < 1)
		return ;
	b->data[b->size] = a->data[0];
	b->size++;
	if (b->size > 1)
	{
		i = b->size - 1;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
	}
	i = 0;
	b->data[0] = a->data[0];
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	ft_printf("pb\n");
	b->operation_count++;
}
