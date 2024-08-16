/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:53 by aumartin          #+#    #+#             */
/*   Updated: 2024/08/16 15:40:09 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**processed_args;

	if (ac < 2 || !av[1][0])
		return (0);
	processed_args = process_arguments(&ac, av);
	if (!validate_input(ac, processed_args))
	{
		if (processed_args != av + 1)
			free_split_args(processed_args);
		print_error_and_exit();
	}
	init_stack(&a, ac);
	init_stack(&b, ac);
	fill_stack(&a, ac, processed_args);
	if (!check_duplicates(a.data, a.size))
	{
		free(a.data);
		free(b.data);
		if (processed_args != av + 1)
			free_split_args(processed_args);
		print_error_and_exit();
	}
	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small_stack(&a, &b);
		else
			sort_big_stack(&a, &b);
	}
	free(a.data);
	free(b.data);
	if (processed_args != av + 1)
		free_split_args(processed_args);
	return (0);
}

