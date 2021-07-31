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

void	init_stack(int	*a)
{
	int		i;

	i = 0;
	while (i < MAX_SIZE)
	{
		a[i] = i;
		i++;
	}
}

void	sqsort(int *a, int	*list, _Bool stack, int len)
{
		int pivot;

}

int		main(int ac, char **av)
{
	int		*a;
	int		list[MAX_SIZE];
	int		heada;
	int		headb;
	int		len = 0;

	a = foreach_arg(ac, av);
	insertion_sort(a);
	init_stack(list);
	sqsort(a, list, 0, len);
}
