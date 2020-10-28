# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ivanrosic <ivanrosic@student.le-101>       +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/02/26 15:48:26 by ivanrosic     #+#   ##    ##    #+#       #
#    Updated: 2020/10/27 14:17:22 by user42      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


.PHONY:	all clean fclean re

NAME			=	Cub3D

PATH_INC		=	includes

PATH_SRC		=	srcs
PATH_OBJ		=	objs
SRC_LIST		=	parsing/ft_parse.c			\
					parsing/ft_struct.c			\
					parsing/ft_open.c			\
					parsing/ft_mlx.c			\
					parsing/ft_map_char_to_int.c\
					parsing/ft_math.c			\

INCS_LIST		=	cub.h

OBJS			=	$(addprefix $(PATH_OBJ)/, $(SRC_LIST:.c=.o))
OBJS_BONUS		=	$(addprefix $(PATH_OBJ)/, $(BONUS_LIST:.c=.o))
INCS			=	$(addprefix $(PATH_INC)/, $(INCS_LIST))

LIBFT_PATH		=	libft
LIBFT_NAME		=	libft.a
LIBFT_FLAG 		=	-Llibft -lft
LIBFT_LIB 		= 	$(FLAG_FT)
LIBFT_INC		=	$(addprefix $(LIBFT_PATH)/, $(PATH_INC))

MINILIBX_PATH	= 	libmlx
MINILIBX_NAME	= 	libmlx_Linux.a
MINILIBX_LIB	=	-Llibmlx -lmlx_Linux

CC				=	gcc
INCLUDES		=	-I$(LIBFT_INC) -I$(MINILIBX_PATH) -I$(PATH_INC)
CFLAGS			=	-Wall -Wextra -Werror
C-O				=	$(CC) $(CFLAGS) $(LIBFT_LIB) $(INCLUDES) -c $< -o $@

DIRS_LIST	= parsing

all:	$(LIBFT_NAME) $(MINILIBX_NAME) $(NAME)
	@ printf "\033[0;38;5;82mCompilation de \033[1mCub3D \033[0;38;5;82mreussis.\n\033[0m"

$(NAME): $(OBJS) $(INCS) comp

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INCS)
	@ $(shell mkdir -p $(PATH_OBJ) $(addprefix $(PATH_OBJ)/, $(DIRS_LIST)))
	@ printf "\033[0;38;5;198mCompilation de $< ..."
	@ $(C-O)
	@ printf "\r                                                                                          \r\033[0m"

$(LIBFT_NAME):
	@ make -C $(LIBFT_PATH)
	@ printf "\033[0;38;5;82mCompilation de la \033[1m$@ \033[0;38;5;82mreussis.\n\033[0m"

$(MINILIBX_NAME):
	@ printf "\033[0m"
	@ make -C $(MINILIBX_PATH)
	@ printf "\033[0;38;5;82mCompilation de la \033[1m$@ \033[0;38;5;82mreussis.\n\033[0m"

bonus: all

clean:
	@ /bin/rm -rf $(PATH_OBJ)
	@ make -C $(LIBFT_PATH) clean
	@ make -C $(MINILIBX_PATH) clean

fclean: clean
	@ make -C $(LIBFT_PATH) fclean
	@ /bin/rm -rf $(NAME) ./$(NAME)* ./*bmp
	@ printf "\033[0;38;5;160mSuppression de \033[1m$(NAME)/$(PATH_OBJ) ..."
	@ sleep 0.5
	@ printf "\r                                                                                          \r\033[0m"
	@ printf "\033[0;38;5;160mSuppression de \033[1m$(NAME)/$(NAME) ..."
	@ sleep 0.5
	@ printf "\r                                                                                          \r\033[0m"
	@ printf "\033[0;38;5;82mSuppression des fichiers de compilation reussis pour \033[1mCub3D.\n"

comp:
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lpthread -lXext

re: fclean all
