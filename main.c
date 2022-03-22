#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "print.c"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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
		while (j > 0 &&  sorted[j - 1] > sorted[j])
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

void	push(t_data *d)
{
		if(d->cursor == d->list.len - 1)
			d->dir = -1;
		else if (d->cursor + d->dir < 0)
			d->dir = +1;	
		d->cursor += d->dir;
		if (d->dir > 0)
			write(1, "pb\n", 3);
		else
			write(1, "pa\n", 3);
}

int		issorted(t_array list)
{
	int		i;

	i = 0;
	while (i < list.len - 1)
	{
		if (list.a[i] > list.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	n_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	push(t_data *d, int dist)
{
	int i;
	char *str;

	if (dist < 0)
		str = "pa\n";
	else 
		str = "pb\n";
	i = 0; 
}

void 	rb(t_data *d, int dist)
{
	int save;
	int i;

	push(d, dist);
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

void 	ra(t_data *d)
{
	int save;
	int i;

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

int		find(t_array *a, int n)
{
	int		i;

	i = 0;
	while (i < a.len)
	{
		if (a.a[i] == n)
			return (i);
		i++;
	}	
}

void	sort(t_data *d)
{
	int		small;
	int		big;
	int		s;
	int		b;

	small = 0;
	big = d->a.len - 1;
	while (small < big)
	{
		s = find(d->a, small) - d->cursor;
		b = find(d->a, big) - d->cursor + 1;
		if (n_abs(s) < n_abs(b))
		{
			small++;
			rra(d, dist);
		}
		else
		{
			big--;
			rb(d, dist);
		}
	}
}

int	main(int ac, char **av)
{
	t_array		sorted;
	t_data		data;

	data.top = 0;
	data.dir = +1;
	data.cursor = 0;
	data.list = foreach_arg(ac, av);
	sorted = insertion_sort(data.list);
	remap(data.list, sorted);
	if (issorted(data.list))
		error();
	sort(&data);
}
