#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 10000

typedef struct s_array
{
	int		*a;
	int		len;
}				t_array;

typedef struct s_stack
{
	int		*list;
	t_array	a;
	int		head;
	int		tail;
}				t_stack;

typedef struct s_data
{
	t_array	list;
	int		top;
	int		dir;
	int		cursor;
}			t_data;

void	error(void);
t_array	foreach_arg(int ac, char **av);

#endif
