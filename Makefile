NAME = cube3d

LIBFT = libft

SRC = cub3d.c util.c 

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))

HEADERS = ft_cub3d.h

FLAGS = -Wall -Wextra -Werror -g -framework OpenGL -framework AppKit

all: MKLIB $(NAME).a

MKLIB:
	make -C $(LIBFT)
$(NAME).a: $(LIBFT)/$(LIBFT).a $(SRC_OBJECTS)
	cp $(LIBFT)/$(LIBFT).a ./$(NAME).a
	ar rcs $(NAME).a $(SRC_OBJECTS)

# $@ -Имя цели обрабатываемого правила
# $< Имя первой зависимости обрабатываемого правила
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
clean:
	@/bin/rm -rf $(SRC_OBJECTS)
	make -C $(LIBFT) clean
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME).a
	make -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re:
	make -C $(LIBFT) fclean
	make fclean
	make all

bonus: all
.PHONY: all clean fclean re