/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:14:56 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:19:15 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacka(t_data *d)
{
	int		vra;
	int		vrra;

	vra = try_ra(d);
	vrra = try_rra(d);
	if (vrra < 0 && vrra <= vra)
	{
		rra(d, 0);
		return (1);
	}
	else if (vra < 0)
	{
		ra(d, 0);
		return (0);
	}
	return (1);
}

int	stackb(t_data *d)
{
	int		vrb;
	int		vrrb;

	vrb = try_rb(d);
	vrrb = try_rrb(d);
	if (vrrb < 0 && vrrb < vrb)
	{
		rrb(d, 0);
		return (0);
	}
	else if (vrb < 0)
	{
		rb(d, 0);
		return (-1);
	}
	return (0);
}

void	distrib(t_data *d)
{
	int		move;

	while (d->cursor >= 0 && d->cursor < d->list.len)
	{
		move = stacka(d) + stackb(d);
		push(d, move);
	}
}
