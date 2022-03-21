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

int	try_ra(t_data *d)
{
	int	last;
	int	elem;
	int before;
	int	after;

	elem = d->list.a[d->cursor];
	last = d->list.len - 1;
	before = n_abs(d->cursor - elem); 
	after = n_abs(last - elem);
	return (after - before);
}

void stacka(t_data *d)
{
	int	new;
	int	val;

	new = 1;
	while (new)
	{
		val = try_ra(d);
		if (val < 0)
		{
			print_stack(d->list, d->cursor);
			new = 1;
			ra(d);
		}
		if ();
		else
			new = 0;
	}
}

int	try_rb(t_data *d)
{
	int	last;
	int	elem;
	int before;
	int	after;

	elem = d->list.a[d->cursor - 1];
	last = 0;
	before = n_abs(d->cursor - 1 - elem); 
	after = n_abs(last - elem);
	return (after - before);
}

void 	rb(t_data *d)
{
	int save;
	int i;

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

void stackb(t_data *d)
{
	int	new;
	int	val;

	new = 1;
	while (new)
	{
		print_stack(d->list, d->cursor);
		val = try_rb(d);
		fflush(stdout);
		if (val < 0)
		{
			new = 1;
			rb(d);
		}
		else
			new = 0;
	}
}

void	sort(t_data *d)
{
	while (!issorted(d->list))
	{
		if (d->cursor > 1)
			stackb(d);
		stacka(d);
		push(d);
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
