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

void 	rb(t_data *d, int dist)
{
	int save;
	int i;

	if (d->cursor < 1)
		return ;
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

void 	ra(t_data *d, int dist)
{
	int save;
	int i;

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

void 	rrb(t_data *d, int dist)
{
	int save;
	int i;

	push(d, dist);
	save = d->list.a[d->cursor - 1];
	i = d->list.len - 2;
	while (i >= d->cursor)
	{
		d->list.a[i + 1] = d->list.a[i];
		i--;
	}
	d->list.a[i + 1] = save;
	write(1, "rra\n", 4);
}

void 	rra(t_data *d, int dist)
{
	int save;
	int i;

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

int		find(t_array a, int n)
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
	int		b;
	int		i;

	i = 0;
	small = 0;
	big = d->list.len - 1;
	while (i < d->list.len)
	{
		s = find(d->list, small) - d->cursor;
		b = find(d->list, big) - d->cursor  - 1;
		if (s && n_abs(s) < n_abs(b))
		{
			small++;
			ra(d, s);
		}
		else if (b)
		{ 
			rb(d, b);
			big--;
		}
		i++;
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
	print_stack(data.list, data.cursor); 
}
