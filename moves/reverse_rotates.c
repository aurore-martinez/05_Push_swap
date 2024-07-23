/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:32:59 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/18 11:33:13 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = temp;
	ft_printf("rra\n");
	a->operation_count++;
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = temp;
	ft_printf("rrb\n");
	b->operation_count++;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
	a->operation_count++;
	b->operation_count++;
}
