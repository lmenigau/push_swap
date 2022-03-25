#include <limits.h>
#include "push_swap.h"

_Bool	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

_Bool	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	parse_int(char *str, int *i)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (is_space(str[*i]))
		(*i)++;
	if (str[*i] == '-')
	{
		neg = -1;
		(*i)++;
	}
	if (!is_num(str[*i]))
		error();
	while (str[*i] && is_num(str[*i]))
	{
		res = res * 10 + (str[*i] - '0') * neg;
		if (res > INT_MAX || res < INT_MIN)
			error();
		(*i)++;
	}
	return (res);
}

void	parse_arg(char *arg, int *restrict tab, int *restrict count)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		tab[*count] = parse_int(arg, &i);
		(*count)++;
		if (arg[i] && !is_space(arg[i]))
			error();
	}
}

t_array	foreach_arg(int ac, char **av)
{
	int			i;
	static int	a[MAX_SIZE];
	static int	count;

	if (ac > MAX_SIZE)
		error();
	i = 1;
	while (i < ac)
	{
		parse_arg(av[i], a, &count);
		i++;
	}
	return ((t_array){a, count});
}
