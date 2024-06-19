##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

NAME	=	syntra

SRC		=	$(shell find src -name '*.c')

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./includes

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all

debug: fclean
	$(CC) -g3 -o $(NAME) $(SRC) $(CFLAGS)
