# **************************************************************************** #
# VARIABLES

NAME				:= philo

FUN					:= 0
CC					:= gcc
CFLAGS				:= -Wall -Werror -Wextra

# **************************************************************************** #
# SOURCES

SRC_PATH = sources/
OBJ_PATH = objects/

SRC		=
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC		= -I ./includes/

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m

# **************************************************************************** #
# RULES

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	echo "make $(NAME)"
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	echo "$(BLUE)$(NAME) compiled and ready to be tested!"
	echo "$(GREEN) Philosophers are ready to die!"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean