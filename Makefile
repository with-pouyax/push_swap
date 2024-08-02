# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC_DIR = src
INCLUDES = -I includes

# Source files
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/operations/push_operations.c \
      $(SRC_DIR)/operations/reverse_rotate_operations.c \
      $(SRC_DIR)/operations/rotate_operations.c \
      $(SRC_DIR)/operations/swap_operations.c \
      $(SRC_DIR)/sort/2_3_4sort.c \
      $(SRC_DIR)/sort/5_sort.c \
      $(SRC_DIR)/sort/radix_sort.c \
      $(SRC_DIR)/sort/sort_utils.c \
      $(SRC_DIR)/utils/process_argument.c \
      $(SRC_DIR)/utils/utils.c \
      $(SRC_DIR)/utils/utils_2.c \
      $(SRC_DIR)/utils/utils_3.c

# Object files
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
