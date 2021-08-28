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

t_array		insertion_sort(t_array a)
{
	static int	sorted[MAX_SIZE];
	int		i;
	int		j;

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

void	init_stack(t_stack *s)
{
	int		list[MAX_SIZE];
	int		i;

	s[0].list = list;
	s[0].head = 0; 
	i = 0;
	while (i < s[0].a.len)
	{
		list[i] = i;
		i++;
	}
}

void	sqsort(t_stack *s, _Bool stack, int pivot, int len)
{
	s[stack].head = pivot + len;	
}

int		main(int ac, char **av)
{
	t_stack		stacks[2];
	t_array		sorted;


	stacks[0].a = foreach_arg(ac, av);
	sorted = insertion_sort(stacks[0].a);
	remap(stacks[0].a, sorted);
	init_stack(stacks);
	sqsort(stacks, 0, stacks[0].a.len / 2, stacks[0].a.len);
}
