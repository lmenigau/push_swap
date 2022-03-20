#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

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

	i = 0;
	while (i < a.len)
	{
		sorted[i] = a.a[i];
		j = i + 1;
		while (sorted[j - 1] < sorted[j])
		{
			swap(&sorted[j], &sorted[j]);
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
				a.a[i] = j;
			j++;
		}
		i++;
	}
}

void	push(t_data *data, char stack)
{
	
}

int		issorted(t_array list)
{
	int		i;

	i = 0;
	while (i < list.len - 1)
	{
		if (list.a[i] > list.a[i + 1]);
			return (0);
		i++;
	}
	return (1);
}

int		try_rotate(t_data *d)
{
	int	last;
	int	elem;
	int before;
	int	after;

	elem = d->list.a[d->cursor];
	last = d->list.len - 1;
	before = d->cursor - elem; 
	after = last - elem;
}

void	sort(t_data *data)
{
	while (!issorted(data->list))
	{
	}
}

int	main(int ac, char **av)
{
	t_stack		stacks[2];
	t_array		sorted;
	t_data		data;

	data.top = 0;
	data.dir = +1;
	data.cursor = 0;
	data.list = foreach_arg(ac, av);
	sorted = insertion_sort(data.list);
	remap(data.list, sorted);
	sort(&data);
}
