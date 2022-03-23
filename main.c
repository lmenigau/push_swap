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

	i = 1;
	while (i < list.len)
	{
		if (list.a[i - 1] > list.a[i])
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
	save = d->list.a[0];
	i = 1;
	while (i <= d->cursor - 1)
	{
		d->list.a[i - 1] = d->list.a[i];
		i++;
	}
	d->list.a[i - 1] = save;
	write(1, "rra\n", 4);
}

void 	rra(t_data *d, int dist)
{
	int save;
	int i;

	push(d, dist);
	save = d->list.a[d->list.len - 1];
	i = d->list.len - 1;
	while (i > d->cursor)
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

int     try_ra(t_data *d)
{
        int     last;
        int     elem;
        int before;
        int     after;

		if (d->cursor > d->list.len - 2)
			return (0);
        elem = d->list.a[d->cursor];
        last = d->list.len - 1;
        before = n_abs(d->cursor - elem);
        after = n_abs(last - elem);
        return (after < before);
}

int     try_rra(t_data *d)
{
        int     last;
        int     elem;
        int before;
        int     after;

		if (d->cursor > d->list.len - 2)
			return (0);
        last = d->list.len - 1;
        elem = d->list.a[last];
        before = n_abs(d->cursor - elem);
        after = n_abs(last - elem);
        return (after < before);
}

int     try_rb(t_data *d)
{
        int     last;
        int     elem;
        int before;
        int     after;

		if (d->cursor < 2)
			return (0);
        elem = d->list.a[d->cursor - 1];
        last = 0;
        before = n_abs(d->cursor - 1 - elem);
        after = n_abs(last - elem);
        return (after < before);
}

int     try_rrb(t_data *d)
{
        int     last;
        int     elem;
        int before;
        int     after;

		if (d->cursor < 2)
			return (0);
        last = 0;
        elem = d->list.a[last];
        before = n_abs(d->cursor - 1 - elem);
        after = n_abs(last - elem);
        return (after < before);
}

void	rr(t_data  *d)
{
			ra(d, 0);
			rb(d, 0);
}

void	rrr(t_data  *d)
{
			rra(d, 0);
			rrb(d, 0);
}

void	distrib(t_data *d)
{
	while (d->cursor < d->list.len)
	{
		print_stack(d->list, d->cursor);
		if (try_ra(d) && try_rb(d))
			rr(d);
		else if (try_ra(d))
			ra(d, 0);
		else if (try_rb(d))
			rb(d, 0);
		else
			push(d, 1);
	}
}

void	sort(t_data *d)
{
	int		small;
	int		big;
	int		s;
	int		b;

	small = 0;
	big = d->list.len - 1;
	while (big >= 0)
	{
		print_stack(d->list, d->cursor);
		s = find(d->list, small) - d->cursor;
		b = find(d->list, big) - (d->cursor - 1);
		if (n_abs(s) < n_abs(b))
		{
			ra(d, s);
			small++;
		}
		else
		{ 
			rb(d, b);
			big--;
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
	{
		error();
		exit(0);
	}
	distrib(&data);
	sort(&data);
	print_stack(data.list, data.cursor);
}
