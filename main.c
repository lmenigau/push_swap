/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:41:14 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:49:08 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	n_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	main(int ac, char **av)
{
	t_array		sorted;
	t_data		data;

	if (ac < 2)
		return (0);
	data.cursor = 0;
	data.list = foreach_arg(ac, av);
	sorted = insertion_sort(data.list);
	isdup(sorted);
	remap(data.list, sorted);
	if (issorted(data.list))
		exit(0);
	if (data.list.len < 6)
		sort_small(&data);
	else if (data.list.len < 128)
	{
		distrib(&data);
		sort(&data);
	}
	else
		radix(&data);
}
