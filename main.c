#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		*insertion_sort(int *a)
{
	static int	sorted[MAX_SIZE];
	(void)a;
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
	int		*a;
	int		list[MAX_SIZE];
	int		len = 0;
	t_stacks	stacks;

	a = foreach_arg(ac, av);
	insertion_sort(a);
	init_stack(list, len);
	sqsort(stacks, 0, len);
}
