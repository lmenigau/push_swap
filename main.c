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

int		isdup(t_array list)
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
	write(1, "rrb\n", 4);
}

void 	rra(t_data *d, int dist)
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
        int     new;
        int     elem;
        int 	before;
        int     after;

		if (d->cursor > d->list.len - 2)
			return (0);
        elem = d->list.a[d->cursor];
        new = d->list.len - 1;
        before = n_abs(d->cursor - elem);
        after = n_abs(new - elem);
        return (after - before);
}

int     try_rra(t_data *d)
{
        int     new;
        int     elem;
        int 	before;
        int     after;

		if (d->cursor > d->list.len - 2)
			return (0);
        elem = d->list.a[d->list.len - 1];
		new = d->cursor;
        before = n_abs(d->list.len - 1 - elem);
        after = n_abs(new - elem);
        return (after - before);
}

int     try_rb(t_data *d)
{
        int     new;
        int     elem;
        int 	before;
        int     after;

		if (d->cursor < 2)
			return (0);
        elem = d->list.a[d->cursor - 1];
        new = 0;
        before = n_abs(d->cursor - 1 - elem);
        after = n_abs(new - elem);
        return (after - before);
}

int     try_rrb(t_data *d)
{
        int     new;
        int     elem;
        int 	before;
        int     after;

		if (d->cursor < 2)
			return (0);
        elem = d->list.a[0];
        new = d->cursor - 1;
        before = n_abs(0 - elem);
        after = n_abs(new - elem);
        return (after - before);
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

int		stacka(t_data *d)
{
	int		vra;
	int		vrra;
	
	vra = try_ra(d);
	vrra = try_rra(d);
	if (vrra < 0 && vrra < vra)
	{
		rra(d, 0);
		return (0);
	}
	else if (vra < 0)
	{
		ra(d, 0);
		return (0);
	}
	return (1);
}

int		stackb(t_data *d)
{
	int		vrb;
	int		vrrb;
	
	vrb = try_rb(d);
	vrrb = try_rrb(d);
	if (vrrb < 0 && vrrb < vrb)
	{
		rrb(d, 0);
		return (1);
	}
	else if (vrb < 0)
	{
		rb(d, 0);
		return (0);
	}
	return (1);
}

void	distrib(t_data *d)
{
	int		move;
	while (d->cursor < d->list.len)
	{
		print_stack(d->list, d->cursor);
		move = stacka(d);
		move &= stackb(d);
		if (move)
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

void	radix(t_data *d)
{
	int mask;
	int	i;

	mask = 1;
	while (mask <= d->list.len)
	{
		i = 0;
		while(i < d->list.len)
		{
			print_stack(d->list, d->cursor);
			if (d->list.a[d->cursor] & mask)
				ra(d, 0);
			else
				push(d, 1);
			i++;
		}
		push(d, -d->cursor);  
		mask <<= 1;
	}
}

void sort_small(t_data *d)
{
	stacka(d); 	
}

int	main(int ac, char **av)
{
	t_array		sorted;
	t_data		data;

	data.cursor = 0;
	data.list = foreach_arg(ac, av);
	sorted = insertion_sort(data.list);
	isdup(sorted);
	print_stack(sorted, data.cursor);
	print_stack(data.list, data.cursor);
	remap(data.list, sorted);
	if (issorted(data.list))
		error();
	print_stack(data.list, data.cursor);
	if (data.list.len < 6)
		sort_small(&data);	
	else if (data.list.len < 128)
		sort(&data);
	else
		radix(&data);
	print_stack(data.list, data.cursor);
}
