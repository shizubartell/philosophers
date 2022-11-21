# **************************************************************************** #
# VARIABLES

NAME				:= philo

FUN					:= 0
CC					:= gcc
CFLAGS				:= -Wall -Werror -Wextra
RM					:= rm -rf

# **************************************************************************** #
# SOURCES

SRCS		 		:= src/actions.c \
						src/printing.c \
						src/utils.c \
						src/main.c

OBJS = $(SRCS:.c=.o)

INC		 			:= /inc

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# RULES

all: $(NAME)

	echo "make $(NAME)"
${NAME}:${OBJS}
	${CC} ${CFLAGS} -I${INC} -o $@ $^
	echo "$(BLUE)$(NAME) compiled and ready to be tested!$(END_COLOR)"
	echo "$(GREEN) Philosophers are ready to die!$(END_COLOR)"

fun: CFLAGS += -D FUN
fun: ${OBJS}
    ${CC} ${CFLAGS} -I${INC} -o $@ $^

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)

re: fclean all
	echo "$(GREEN)Cleaned up all files for $(NAME)!"

.PHONY: all re clean fclean
