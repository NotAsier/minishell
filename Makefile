NAME = minishell

SRC =											\
		src/main.c								\
												\
		src/readline/readline.c				\
												\
		src/tokenizer/store_tokens.c			\
		src/tokenizer/store_tokens_utils.c		\
		src/tokenizer/tokens_to_pipas.c		\
		src/tokenizer/utils.c					\
												\
		src/executor/find_command.c			\
		src/executor/exec_cmd.c				\
		src/executor/executor.c				\
		src/executor/cmd_type.c				\
												\
		src/utils/errors.c						\
		src/utils/environment.c				\
		src/readline/expand_token.c			\
		src/readline/malloc_expand_token.c		\
		src/readline/malloc_expand_token_aux.c	\
		src/readline/copy_join.c 				\
												\
		src/builtins/builtins.c				\
		src/builtins/cd.c						\
		src/builtins/echo.c					\
		src/builtins/env.c						\
		src/builtins/exit.c					\
		src/builtins/export.c					\
		src/builtins/pwd.c						\
		src/builtins/unset.c					\
												\
		src/builtins/signals.c					\
		

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAG	 = -Wall -Wextra -Werror -g3 #-fsanitize=address
CFLAG	+= -I inc
CFLAG	+= -I libft
READLINE = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAG) $(OBJ) $(LIB) $(READLINE) -o $(NAME)
	
all: $(NAME)

clean:
	make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re