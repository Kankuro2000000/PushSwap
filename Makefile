NAME = push_swap

SRCS = push_swap.c act1.c act2.c act3.c best_move.c check_1.c check_2.c \
		cost_place.c fill_right_and_back.c int_to_stack.c last_chance.c \
		pre_sort.c sort_3_5.c stack_create.c

HEADER = push_swap.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		: $(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(SRCS) -o $@	

clean	:
		rm -f $(OBJ)

fclean  :   clean
		rm -f $(NAME)

re      :   fclean all