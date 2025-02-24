/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:35:53 by aumartin          #+#    #+#             */
/*   Updated: 2025/02/24 16:09:07 by aumartin         ###   ########.fr       */
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
	if (a->data[0] == max_value)
		ra(a);
	else if (a->data[1] == max_value)
		rra(a);
	if (a->data[0] > a->data[1])
		sa(a);
}

/* Trie une pile de 5 éléments
Factorise en n fois
Déplace les 2 plus petits dans b (car 5 - 3 de sort_3)
Trie les 3 restants dans a
Réinsère tous les éléments de b dans a
*/
void	sort_5(t_stack *a, t_stack *b)
{
	move_n_min_to_b(a, b, 2);
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

/* Trie une pile de 10 éléments
Déplace les 5 plus petits dans b
Trie les 5 restants dans a
Réinsère tous les éléments de b dans a
*/
void	sort_10(t_stack *a, t_stack *b, int size)
{
	move_n_min_to_b(a, b, size - 5);
	sort_5(a, b);
	while (b->size > 0)
		pa(a, b);
}

/* Trie une pile de n éléments de manière générique
Déplace les n-3 plus petits éléments dans b :
	Trouver l'index du plus petit élément
	Déplacer le minimum en tête de a
	Pousser le min dans b
Trier les 3 éléments restants dans a avec sort_3
Réinsérer tous les éléments de b dans a
*/
/* void	sort_n(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	min_index;
	int	to_move;

	to_move = n - 3;
	while (to_move-- > 0)
	{
		min_index = 0;
		i = 1;
		while (i < a->size)
		{
			if (a->data[i] < a->data[min_index])
				min_index = i;
			i++;
		}
		if (min_index <= a->size / 2)
		{
			while (min_index > 0)
			{
				ra(a);
				min_index--;
			}
		}
		else
		{
			while (min_index < a->size)
			{
				rra(a);
				min_index++;
			}
		}
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
	{
		pa(a, b);
	}
} */

/* 	else if (a->size <= 10)
		sort_n(a, b, a->size); */
void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else if (a->size <= 10)
		sort_10(a, b, a->size);
}

/* void	sort_3(t_stack *a)
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
} */

/* void	sort_5(t_stack *a, t_stack *b)
{
	min_to_top_a(a); // Amène le plus petit en tete
	pb(a, b);        // Pousse le plus petit dans b

	min_to_top_a(a); // Amène le 2e plus petit en tete
	pb(a, b);        // Pousse le 2e plus petit dans b

	sort_3(a);       // Trie les 3 éléments restants

	pa(a, b);        // Réinsère le 2e plus petit
	pa(a, b);        // Réinsère le plus petit
} */

/* void	sort_5(t_stack *a, t_stack *b)
{
	print_stack(a, b);
	while (a->size > 3)
	{
		pb(a, b);
		print_stack(a, b);
	}
	sort_3(a);
	print_stack(a, b);
	while (b->size > 0)
	{
		pa(a, b);
		print_stack(a, b);
	}
	// finalize_sort(a);
	print_stack(a, b);
} */

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

/* void	sort_5(t_stack *a, t_stack *b)
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
*/

/* void	sort_10(t_stack *a, t_stack *b)
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
} */
