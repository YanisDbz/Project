NAME	=	sta

SRC	=	main.c \
		getCreature.c \
		my_put_nbr.c \
		readLine.c \
		my_string.c \
		attak.c \
		containerCreature.c \
		commandeTaper.c \
		my_getnbr.c

OBJ	=	*.o

FLAG	=	-W -Wall -Wextra -Werror

TMP	=	*~

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(FLAG) $(SRC)
	rm -rf $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) $(TMP)

re:	fclean	all
