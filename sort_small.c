/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:20:14 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:21:31 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *d)
{
	if (d->cursor > d->list.len - 1)
		return ;
	if (d->list.a[d->cursor] > d->list.a[d->cursor + 1])
	{
		swap(&d->list.a[d->cursor], &d->list.a[d->cursor + 1]);
		write(1, "sa\n", 3);
	}
}	

int	sort_3(t_data *d)
{
	stacka(d);
	sa(d);
	stacka(d);
	if (issorted(d->list))
		return (1);
	rra(d, 0);
	sa(d);
	if (issorted(d->list))
		return (1);
	return (0);
}

void	sort_small(t_data *d)
{
	int		i;

	i = 0;
	if (d->list.len > 3)
	{
		stacka(d);
		while (d->list.a[d->cursor] != 0)
			ra(d, 0);
		push(d, 1);
	}
	if (d->list.len > 4)
	{
		stacka(d);
		while (d->list.a[d->cursor] != 1)
			ra(d, 0);
		push(d, 1);
	}
	sort_3(d);
	push(d, -d->cursor);
}
