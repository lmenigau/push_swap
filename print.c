#include <stdio.h>

void	print_stack(t_array a, int mid)
{
	for (int i = 0; i < a.len; i++)
	{
		if (i == mid)
			fprintf(stderr, "|");
		fprintf(stderr, "%3d",  a.a[i]);
	}
	fprintf(stderr, "\n");
	fflush(stderr);
}
