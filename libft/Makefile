# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 00:48:32 by kshantel          #+#    #+#              #
#    Updated: 2020/08/26 17:43:43 by kshantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_lstadd_back.c ft_lstsize.c ft_lstnew.c ft_lstlast.c get_next_line.c\
		ft_putchar.c ft_putstr.c

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	@ar rc $(NAME) $(SRC_OBJECTS)
	@ranlib $(NAME)

# $@ -Имя цели обрабатываемого правила
# $< Имя первой зависимости обрабатываемого правила
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
clean:
	@/bin/rm -rf $(SRC_OBJECTS)
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all
