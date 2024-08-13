/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:53 by aumartin          #+#    #+#             */
/*   Updated: 2024/08/13 15:31:04 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (!validate_input(argc, argv))
		print_error_and_exit();
	init_stack(&a, argc - 1);
	init_stack(&b, argc - 1);
	fill_stack(&a, argc, argv);
	a.size = argc - 1;
	if (!check_duplicates(a.data, a.size))
		print_error_and_exit();
	if (a.size <= 2)
		sort_2(&a);
	else if (a.size == 3)
		sort_3(&a);
	else if (a.size <= 5)
		sort_5(&a, &b);
	else
		radix_sort(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
} */
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

/* 	ft_printf("a.size %d\n", a.size);
	for (int j = 0; j < a.size; j++)
		ft_printf("Stack filled. Data[%d]: %d\n", j, a.data[j]); */

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
		if (a.size <= 2)
			sort_2(&a);
		else if (a.size == 3)
			sort_3(&a);
		else if (a.size <= 5)
			sort_5(&a, &b);
		else
			radix_sort(&a, &b);
	}

/* 	for (int j = 0; j < a.size; j++)
		ft_printf("Stack sorted. Data[%d]: %d\n", j, a.data[j]); */

	free(a.data);
	free(b.data);
	if (processed_args != av + 1)
		free_split_args(processed_args);
	return (0);
}
