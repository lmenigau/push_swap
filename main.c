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
	static int	sorted[100000];

	return (sorted);
}

int	main(int ac, char **av)
{
	int		*a;

	a = foreach_arg(ac, av);
}
