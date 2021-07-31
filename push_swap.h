#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 10000

typedef struct	s_stacks
{
	int		*a;
	int		*list;
	int		heada;
	int		headb;
}				t_stacks;

void	error(void);
int	*foreach_arg(int ac, char **av);


#endif
