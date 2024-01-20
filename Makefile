CC = cc
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 
SRCS = get_next_line/get_next_line.c \
	   main.c utils.c
# CFLAGS = -O3 -glldb  -Wall -Wextra -Werror
CFLAGS =  -glldb
OBJS_FOLDER = objs


OBJS = ${SRCS:%.c=$(OBJS_FOLDER)/%.o}
NAME = miniRT

all: $(NAME)

$(NAME): $(OBJS_FOLDER) $(OBJS)
	$(MAKE) -C ./libft
	$(CC)  $(OBJS) $(CFLAGS) $(MLXFLAGS) libft/libft.a -o $(NAME) 

$(OBJS_FOLDER):
	mkdir -p objs
	mkdir -p objs/get_next_line

${OBJS_FOLDER}/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	# $(MAKE) clean -C ./libft
	rm -rf $(OBJS_FOLDER)

fclean: clean
	# $(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
