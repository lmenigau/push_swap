/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:19:54 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:19:56 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_array a, int n)
{
	int		i;

	i = 0;
	while (i < a.len && a.a[i] != n)
		i++;
	return (i);
}

void	sort(t_data *d)
{
	int		small;
	int		big;
	int		s;

	small = 0;
	big = d->list.len - 1;
	while (small <= big)
	{
		s = find(d->list, small) - d->cursor;
		ra(d, s);
		small++;
	}
}

void	radix(t_data *d)
{
	int		mask;
	int		i;

	mask = 1;
	while (mask <= d->list.len)
	{
		i = 0;
		while (i < d->list.len)
		{
			if (d->list.a[d->cursor] & mask)
				ra(d, 0);
			else
				push(d, 1);
			i++;
		}
		push(d, -d->cursor);
		mask <<= 1;
	}
}
