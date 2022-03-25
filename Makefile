SRC		= array_util.c distrib.c foreach_arg.c main.c\
		  radix.c sort_small.c stack_op.c try.c
OBJ		= $(SRC:.c=.o)
CFLAGS	= -g -Wall -Wextra -Werror 
NAME	= push_swap
CC		= clang
ifeq  '$(shell ar V 2>/dev/null | head -c 3)' 'GNU'
	ARFLAGS	= Ur
endif

$(NAME) : $(OBJ) 
	$(CC)  -o $(NAME) $(CFLAGS) $(OBJ) 

.PHONY	: re clean fclean all

fclean	: clean
		$(RM) $(NAME)

clean	:
		$(RM) *.o

re		: fclean  all

all		: $(NAME)
