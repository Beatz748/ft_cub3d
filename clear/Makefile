MLX = -lmlx -lm -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = cub3d

SRCS = util.c ft_parsing_textures.c ft_parsing.c util2.c util3.c cub3d.c

OBJSRCS = $(SRCS:.c=.o) 

$(NAME) : $(OBJSRCS)
	@echo "\033[33m[Cub3D compilation...]"
	@gcc $(OBJSRCS) -Wall -Wextra -Werror $(MLX)  -o $(NAME)
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)

fclean : clean 
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)