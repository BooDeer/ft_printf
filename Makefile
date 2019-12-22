# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 19:10:52 by hboudhir          #+#    #+#              #
#    Updated: 2019/12/02 22:41:57 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
NAME = libftprintf.a
LIB = libft/libft.h srcs/ft_printf.h
flags = -Wall -Wextra -Werror
FILES =	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_strlcat.c srcs/ft_print.c libft/ft_lstadd_back.c libft/ft_lstnew.c srcs/ft_getls.c speficiers/ft_c_speficier.c speficiers/ft_p_specifier.c speficiers/ft_bigx_speficier.c speficiers/ft_d_speficier.c speficiers/ft_percent_speficier.c speficiers/ft_s_speficier.c speficiers/ft_u_speficier.c speficiers/ft_x_speficier.c srcs/ft_decitohex.c
OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strlcat.o ft_print.o ft_lstadd_back.o ft_lstnew.o ft_getls.o ft_c_speficier.o ft_bigx_speficier.o ft_d_speficier.o ft_p_specifier.o ft_percent_speficier.o ft_s_speficier.o ft_u_speficier.o ft_x_speficier.o ft_decitohex.o

all: $(NAME)
	@echo "Creating the library . . . . ."
$(NAME):
	@$(CC) $(flags) -c $(FILES) -I $(LIB)
	@$(AR) rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@echo "Cleaning *.o files . . . . ."
	@rm -rf $(OBJ)
fclean: clean
	@echo "Cleaning all files . . . . ."
	@rm -rf $(NAME)
bonus:
	@echo "Nothing here . . . . ."
re: fclean all
	@echo "Recreating the library . . . . ."o