#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 10000

typedef struct	s_stacks
{
	int		*a;
	int		*list;
	int		heada;
	int		headb;
	int		taila;
	int		tailb;
}				t_stacks;

typedef	struct	s_array
{
	int		*a;
	int		len;
}				t_array;

void	error(void);
int		*foreach_arg(int ac, char **av);


#endif
