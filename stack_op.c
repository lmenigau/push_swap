/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:20:51 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:21:39 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *d, int dist)
{
	int		i;
	char	*str;

	d->cursor += dist;
	if (dist < 0)
		str = "pa\n";
	else
		str = "pb\n";
	i = 0;
	while (i < n_abs(dist))
	{
		write(1, str, 3);
		i++;
	}
}

void	rb(t_data *d, int dist)
{
	int		save;
	int		i;

	push(d, dist);
	if (d->cursor < 1)
		return ;
	save = d->list.a[d->cursor - 1];
	i = d->cursor - 2;
	while (i >= 0)
	{
		d->list.a[i + 1] = d->list.a[i];
		i--;
	}
	d->list.a[i + 1] = save;
	write(1, "rb\n", 3);
}

void	ra(t_data *d, int dist)
{
	int		save;
	int		i;

	push(d, dist);
	save = d->list.a[d->cursor];
	i = d->cursor + 1;
	while (i < d->list.len)
	{
		d->list.a[i - 1] = d->list.a[i];
		i++;
	}
	d->list.a[i - 1] = save;
	write(1, "ra\n", 3);
}

void	rrb(t_data *d, int dist)
{
	int		save;
	int		i;

	push(d, dist);
	save = d->list.a[0];
	i = 1;
	while (i <= d->cursor - 1)
	{
		d->list.a[i - 1] = d->list.a[i];
		i++;
	}
	d->list.a[i - 1] = save;
	write(1, "rrb\n", 4);
}

void	rra(t_data *d, int dist)
{
	int		save;
	int		i;

	push(d, dist);
	save = d->list.a[d->list.len - 1];
	i = d->list.len - 2;
	while (i >= d->cursor)
	{
		d->list.a[i + 1] = d->list.a[i];
		i--;
	}
	d->list.a[i + 1] = save;
	write(1, "rra\n", 4);
}
