#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		*insertion_sort(t_array a)
{
	static int	sorted[MAX_SIZE];
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	return (sorted);
}

void	init_stack(int	*a, int len)
{
	int		i;

	i = 0;
	while (i < MAX_SIZE)
	{
		a[i] = i;
		i++;
	}
}

void	sqsort(t_stacks stacks, _Bool stack, int len)
{
		int pivot;

		pivot = 40;
}

int		main(int ac, char **av)
{
	int		list[MAX_SIZE];
	int		len = 0;
	t_stacks	stacks;
	t_array		a;

	a = foreach_arg(ac, av);
	insertion_sort(a);
	init_stack(list, len);
	sqsort(stacks, 0, len);
}
