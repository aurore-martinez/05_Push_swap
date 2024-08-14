/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:58:58 by aumartin          #+#    #+#             */
/*   Updated: 2024/08/14 10:46:18 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
