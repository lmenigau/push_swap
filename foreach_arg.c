/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:15:06 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 11:16:21 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

_Bool	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

_Bool	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	parse_int(char *str, int *i)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	if (str[*i] == '-')
	{
		neg = -1;
		(*i)++;
	}
	if (!is_num(str[*i]))
		error();
	while (str[*i] && is_num(str[*i]))
	{
		res = res * 10 + (str[*i] - '0') * neg;
		if (res > INT_MAX || res < INT_MIN)
			error();
		(*i)++;
	}
	return (res);
}

void	parse_arg(char *arg, int *restrict tab, int *restrict count)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		while (is_space(arg[i]))
			i++;
		tab[*count] = parse_int(arg, &i);
		(*count)++;
		while (is_space(arg[i]))
			i++;
	}
}

t_array	foreach_arg(int ac, char **av)
{
	int			i;
	static int	a[MAX_SIZE];
	static int	count;

	if (ac > MAX_SIZE)
		error();
	i = 1;
	while (i < ac)
	{
		parse_arg(av[i], a, &count);
		i++;
	}
	return ((t_array){a, count});
}
