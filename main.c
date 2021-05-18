#include <limits.h>
#include <unistd.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

_Bool	is_num(char c)
{
	return (c >= '0' || c <= '9');
}

int		parse_int(char *str)
{
	int		i;
	long	res;
	int		neg;
	int		d;
	
	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && is_num(str[i]))
	{
		res = res * 10 + (str[i] - '0') * neg;
	}
	if (res > INT_MAX || res < INT_MIN)
		error();
	return (res);
}

int	*parse_arg(int ac, char **av)
{
	int		i;
	int		*tab;

	i = 1;
	tab = malloc(ac * sizeof(*tab));
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[i - 1] = parse_int(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		*tab;
	int		len;

	if (ac < 2)
		tab = parse_arg(ac, av);
	if (!tab)
		error();
}
