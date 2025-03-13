/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:53 by aumartin          #+#    #+#             */
/*   Updated: 2025/02/24 16:00:34 by aumartin         ###   ########.fr       */
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
	setup_stack(&a, &b, ac, processed_args);
	if (!check_duplicates(a.data, a.size))
	{
		cleanup_stack(&a, &b, av, processed_args);
		print_error_and_exit();
	}
	sort_stack(&a, &b);
	cleanup_stack(&a, &b, av, processed_args);
	return (0);
}
