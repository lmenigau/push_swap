/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:10:26 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:10:28 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

t_array	insertion_sort(t_array a)
{
	static int	sorted[MAX_SIZE];
	int			i;
	int			j;

	i = 1;
	sorted[0] = a.a[0];
	while (i < a.len)
	{
		sorted[i] = a.a[i];
		j = i;
		while (j > 0 && sorted[j - 1] > sorted[j])
		{
			swap(&sorted[j - 1], &sorted[j]);
			j--;
		}
		i++;
	}
	return ((t_array){sorted, a.len});
}

void	remap(t_array a, t_array sorted)
{
	int		i;
	int		j;

	i = 0;
	while (i < a.len)
	{
		j = 0;
		while (j < sorted.len)
		{
			if (a.a[i] == sorted.a[j])
			{
				a.a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	isdup(t_array list)
{
	int		i;

	i = 0;
	while (i + 1 < list.len)
	{
		if (list.a[i + 1] == list.a[i])
			error();
		i++;
	}
	return (1);
}

int	issorted(t_array list)
{
	int		i;

	i = 1;
	while (i < list.len)
	{
		if (list.a[i - 1] > list.a[i])
			return (0);
		i++;
	}
	return (1);
}
