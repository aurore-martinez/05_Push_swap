/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:58:58 by aumartin          #+#    #+#             */
/*   Updated: 2025/02/24 16:06:53 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_args(char **split_args)
{
	int	i;

	if (split_args)
	{
		i = 0;
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
	}
}

char	**process_arguments(int *argc, char **argv)
{
	char	**processed_args;

	processed_args = NULL;
	if (*argc == 2)
	{
		processed_args = ft_split(argv[1], ' ');
		if (!processed_args)
			print_error_and_exit();
		*argc = 0;
		while (processed_args[*argc])
		{
			(*argc)++;
		}
	}
	else
	{
		processed_args = argv + 1;
		(*argc)--;
	}
	return (processed_args);
}

int	contains_negative(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->size <= 10)
			sort_small_stack(a, b);
		else
			sort_big_stack(a, b);
	}
}
