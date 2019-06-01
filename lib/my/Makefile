##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_inseg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_putnbr_base.c	\
		my_strdup.c	\
		my_calloc.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_char.c	\
		my_clear_str.c	\
		check_num.c	\
		usage.c	\
		strcpy_end.c	\
		my_putstrn.c	\
		get_next_line.c	\
		get_flags.c	\
		check_flags.c	\
		get_args.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
