##
## EPITECH PROJECT, 2023
## B-OOP-400-BDX-4-1-tekspice-johanna.bureau
## File description:
## Makefile
##

SRC = ex06.c

CFLAGS = -Wall -Wextra -Werror

NAME	=	ex06

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re