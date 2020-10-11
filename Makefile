SRCS			=	srcs/ft_bmp.c srcs/ft_direction.c srcs/ft_drawing.c srcs/ft_errors.c\
					srcs/ft_keys.c srcs/ft_math.c srcs/ft_par_res.c srcs/ft_parser_2.c srcs/ft_parser.c\
					srcs/ft_parsing_textures.c srcs/ft_player.c srcs/ft_rc_util.c srcs/ft_sprite.c\
					srcs/ft_util_gnl.c srcs/ft_util_list.c srcs/ft_util.c srcs/ft_validation_util.c\
					srcs/main.c srcs/ft_map.c\

INC				=	cub3d.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Iinc/ -Imlx/ -Wall -Werror -Wextra
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib
NAME			= cub3d

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS) $(INCS)
				@cp mlx/$(MLX) .
				gcc ${CFLAGS} -o cub3d ${OBJS} ${LIBS}
				@echo "Done"

$(MLX):
				@make -C mlx

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME) $(MLX)
					@make clean -C mlx

re:				fclean $(NAME)

.PHONY:			all clean fclean re
