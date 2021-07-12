SRC		= main.c foreach_arg.c
OBJ		= $(SRC:.c=.o)
CFLAGS	= -g -Wall -Wextra -fsanitize=address
NAME	= push_swap
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
