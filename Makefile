NAME	= so_long
# CFLAGS	= -Wextra -Wall -Werror

# Paths for MLX42
LIBMLX	= /Users/riel-fas/MLX42
MLX_INCLUDE	= $(LIBMLX)/include/MLX42
MLX_LIB	= $(LIBMLX)/build/libmlx42.a

# Paths for GLFW
GLFW_INCLUDE = /Users/riel-fas/goinfre/homebrew/include
GLFW_LIB = /Users/riel-fas/goinfre/homebrew/lib

# Include paths
HEADERS	= -I ./include -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)

# Libraries
LIBS = $(MLX_LIB) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm

# Source files
SRCS	= main.c keyboard.c
OBJS	= ${SRCS:.c=.o}




all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
