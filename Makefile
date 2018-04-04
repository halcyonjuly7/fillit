NAME = fillit
LIBFT = libft/libft.a
CONFIG = gcc -I libft/ -Wall -Wextra -Werror $(SRC) -c
CONFIG2 = gcc -L libft -lft $(OBJ) -o fillit
SRC = main.c\
      normalize.c\
      piece.c\
      validator.c\
      solver.c\
      map.c\
      cleaner.c\
      tetramino.c

OBJ = $(patsubst %.c, %.o, $(SRC))
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all