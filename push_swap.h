/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeniga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:19:50 by lomeniga          #+#    #+#             */
/*   Updated: 2022/03/25 07:19:51 by lomeniga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

# define MAX_SIZE 150000

typedef struct s_array
{
	int		*a;
	int		len;
}				t_array;

typedef struct s_data
{
	t_array	list;
	int		cursor;
}			t_data;

void	error(void);
int		n_abs(int n);
t_array	foreach_arg(int ac, char **av);

void	sort_small(t_data *d);
int		try_ra(t_data *d);
int		try_rra(t_data *d);
int		try_rb(t_data *d);
int		try_rrb(t_data *d);
void	rra(t_data *d, int dist);
void	ra(t_data *d, int dist);
void	rb(t_data *d, int dist);
void	rrb(t_data *d, int dist);
void	push(t_data *d, int dist);
t_array	insertion_sort(t_array a);
int		isdup(t_array list);
void	remap(t_array a, t_array sorted);
void	distrib(t_data *d);
void	sort(t_data *d);
void	radix(t_data *d);
int		issorted(t_array list);
void	swap(int *a, int *b);
int		stacka(t_data *d);
#endif
