/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:31:09 by aumartin          #+#    #+#             */
/*   Updated: 2024/09/03 14:32:49 by aumartin         ###   ########.fr       */
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
