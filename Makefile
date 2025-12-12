# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 07:52:02 by mamarti           #+#    #+#              #
#    Updated: 2025/12/12 16:09:39 by mamarti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c ft_printf.c ft_printf_utils.c \
				ft_printf_functions.c get_next_line.c

SRCS_DIR	=		srcs
SRCS		=		$(addprefix $(SRCS_DIR)/, $(SRC))
OBJ_DIR		=		objs
OBJS		=		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS		=		$(OBJS:.o=.d)
NAME		=		libft.a
CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror -Iincludes -MMD -MP

GREEN = \033[38;2;41;169;41m
NC = \033[0m

define ECHO_SUCCESS
	@echo "$(GREEN)[Libft] Compilation success!$(NC)"
endef

$(OBJ_DIR)/%.o: 	$(SRCS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
					ar rc $(NAME) $(OBJS)
					$(ECHO_SUCCESS)
				
all:				$(NAME)

clean:
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus

-include $(DEPS)