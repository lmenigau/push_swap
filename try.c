/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:13:26 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:14:39 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_ra(t_data *d)
{
	int		new;
	int		elem;
	int		before;
	int		after;

	if (d->cursor > d->list.len - 2)
		return (0);
	elem = d->list.a[d->cursor];
	new = d->list.len - 1;
	before = n_abs(d->cursor - elem);
	after = n_abs(new - elem);
	return (after - before);
}

int	try_rra(t_data *d)
{
	int		new;
	int		elem;
	int		before;
	int		after;

	if (d->cursor > d->list.len - 2)
		return (0);
	elem = d->list.a[d->list.len - 1];
	new = d->cursor;
	before = n_abs(d->list.len - 1 - elem);
	after = n_abs(new - elem);
	return (after - before);
}

int	try_rb(t_data *d)
{
	int		new;
	int		elem;
	int		before;
	int		after;

	if (d->cursor < 2)
		return (0);
	elem = d->list.a[d->cursor - 1];
	new = 0;
	before = n_abs(d->cursor - 1 - elem);
	after = n_abs(new - elem);
	return (after - before);
}

int	try_rrb(t_data *d)
{
	int		new;
	int		elem;
	int		before;
	int		after;

	if (d->cursor < 2)
		return (0);
	elem = d->list.a[0];
	new = d->cursor - 1;
	before = n_abs(0 - elem);
	after = n_abs(new - elem);
	return (after - before);
}
