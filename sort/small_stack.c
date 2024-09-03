/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:35:53 by aumartin          #+#    #+#             */
/*   Updated: 2024/09/03 14:28:55 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/* void	sort_5(t_stack *a, t_stack *b)
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
} */

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_value;
	int	min_index;

	while (a->size > 3)
	{
		find_min(a, &min_value, &min_index);
		move_min_to_top(a, min_index);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_10(t_stack *a, t_stack *b)
{
	int	min_value;
	int	min_index;
	int	count;

	count = 0;
	while (a->size > 5)
	{
		find_min(a, &min_value, &min_index);
		move_min_to_top(a, min_index);
		pb(a, b);
		count++;
	}
	sort_5(a, b);
	while (count-- > 0)
		pa(a, b);
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else if (a->size <= 10)
		sort_10(a, b);
}
