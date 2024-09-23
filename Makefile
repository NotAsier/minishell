# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 13:01:04 by aarranz-          #+#    #+#              #
#    Updated: 2024/09/23 12:24:39 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell
OBJ_DIR		:=	obj/
SRC_PATH	:=	src/
LIBFT_PATH	:=	libft
LIBFT		:=	libft.a
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -Iinc -g3
RLINE_FLAGS	:= -I/usr/include/readline -lreadline #-L/Users/$(USER)/.brew/opt/readline/lib/

# SRCS #
BUILTINS	:= builtins cd echo env export pwd signals unset
EXECUTOR	:= cmd_type exec_cmd executor find_command
READLINE 	:= copy_join expand_token malloc_expand_token malloc_expand_token_aux readline
TOKENIZER 	:= store_tokens store_tokens_utils tokens_to_pipas utils
MAIN	 	:= main
UTILS 		:= enviroment errors




PLAIN_SRCS =	$(addsuffix .c, $(addprefix builtins/,	$(BUILTINS)))		\
				$(addsuffix .c, $(addprefix executor/,	$(EXECUTOR)))		\
				$(addsuffix .c, $(addprefix readline/,	$(READLINE)))		\
				$(addsuffix .c, $(addprefix tokenizer/,	$(TOKENIZER)))		\
				$(addsuffix .c, $(addprefix utils/,		$(UTILS)))			\
				$(addsuffix .c, $(addprefix main/,		$(MAIN)))

SRCS := $(addprefix $(SRC_PATH), $(PLAIN_SRCS))
OBJS := $(addprefix $(OBJ_DIR), $(PLAIN_SRCS:.c=.o))


all: $(NAME)


$(NAME): $(OBJS) $(LIBFT)
	@clear
	@printf "\033[0;32;3mLIBFT\t\t\033[0;32;0m✅\n"
	@sleep 0.2;
	@printf "\033[0;32;3mMINISHELL\t\033[0;32;0m✅\033[0;32;3m\n\n"
	@$(CC) $(CFLAGS) $(RLINE) $(OBJS) $(LIBFT) $(RLINE_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(RLINE_FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT) ./

clean:
	@rm -fr $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@make fclean -C $(LIBFT_PATH)
	
re: fclean all

.PHONY: all clean fclean re