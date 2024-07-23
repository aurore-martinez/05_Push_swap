/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:18:56 by aumartin          #+#    #+#             */
/*   Updated: 2024/07/18 11:29:04 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = temp;
	ft_printf("sa\n");
	a->operation_count++;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = temp;
	ft_printf("sb\n");
	b->operation_count++;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
	a->operation_count++;
	b->operation_count++;
}
