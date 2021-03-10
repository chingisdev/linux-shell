# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 17:56:31 by ctycho            #+#    #+#              #
#    Updated: 2021/03/09 21:08:37 by mvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	minishell

#flags------------------------------------------------------------------------

CC		:=	gcc
FLAG	:=	-I.
RM		:=	rm -f
AR		:=	ar rc

#directories------------------------------------------------------------------

LIB_D	:=	./libft/
GNL_D	:=	./get_next_line/
BUILT	:=	./builtins/
ENV		:=	./env/
TOOL	:=	./tools/
INC_D	:=	./include/

#files------------------------------------------------------------------------

INC		:=	minishell.h
SRCS	:=	main_test.c bin.c bin1.c parser.c mini_pipes.c \
			$(addprefix ${TOOL}, libft_utils.c ft_error.c mini_utils.c) \
			$(addprefix $(ENV), ft_shlvl.c ft_pwd.c) \
			$(addprefix ${BUILT}, mini_cd.c mini_echo.c mini_env.c mini_exit.c \
			mini_export.c mini_pwd.c mini_unset.c)

#colors----------------------------------------------------------------------

GREEN	:=	\033[0;32m
CYAN	:=	\033[0;36m
MAGENTA	:=	\033[0;35m
LGREEN	:=	\033[1;32m
LYELLOW	:=	\033[1;33m
LRED	:=	\033[1;31m
LBLUE	:=	\033[1;34m	

#rules------------------------------------------------------------------------

all: makelib makegnl $(NAME)

makelib:
	@cd $(LIB_D) && make

makegnl:
	@cd $(GNL_D) && make

${NAME}: $(SRCS) ${INC}
	@$(CC) -o $(NAME) $(SRCS) $(LIB_D)libft.a $(GNL_D)gnl.a $(FLAG)
	@echo "${CYAN}Library "${NAME}" succesfully compiled"

clean:		
	#@rm -f ${NAME}
	@cd $(LIB_D) && make clean
	@cd $(GNL_D) && make clean
	@echo "${LGREEN}Everything is cleaned succesfully"

fclean:
	@rm -f ${NAME}
	@echo "${LGREEN}Everything is cleaned succesfully"
	@cd $(LIB_D) && make fclean
	@cd $(GNL_D) && make fclean

re:			fclean all
	@echo "${LBLUE}Library successfuly rebuilt"
