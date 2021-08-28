#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 10000


typedef	struct	s_array
{
	int		*a;
	int		len;
}				t_array;

typedef struct	s_stack
{
	int		*list;
	t_array	a;
	int		head;
	int		tail;
}				t_stack;


void	error(void);
t_array	foreach_arg(int ac, char **av);


#endif
