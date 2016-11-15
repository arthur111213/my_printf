##
## Makefile for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Wed Nov  9 10:51:50 2016 Arthur Baurens
## Last update Tue Nov 15 20:25:33 2016 Arthur Baurens
##

CC			=	gcc

PRINTER		=	print/indent_gestioner.c	\
				print/print_pointers.c		\
				print/print_spec_str.c		\
				print/print_purcent.c		\
				print/print_hex_up.c		\
				print/print_binary.c		\
				print/print_octal.c			\
				print/print_uint.c			\
				print/print_char.c			\
				print/print_str.c			\
				print/print_int.c			\
				print/print_hex.c

SRC			=	$(PRINTER)			\
				my_strings.c		\
				my_printf.c			\
				parsing.c			\
				numbers.c			\
				flags.c				\
				lists.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

INCLUDE		=	-I./include

CFLAGS		=	$(INCLUDE) -g #-W -Wall -Werror -ansi -pedantic

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME) test

re:	fclean test

test:	all
	$(CC) -g -I./include -L./ -o test main.c -lmy

.PHONY:	all clean fclean re
