# **************************************************************************** #
# VARIABLES

NAME = philo

CFLAGS = -g -Wall -Wextra -Werror -pthread

# **************************************************************************** #
# SOURCES

INC = inc/

SRC_FILES = main.c actions.c printing.c search_and_destroy.c \
			initialize.c utils.c
			

SRC = ${addprefix src/, ${SRC_FILES}}

OBJS = ${SRC:.c=.o}

RM = rm -rf

NR = norminette -R CheckForbiddenSourceHeader

# **************************************************************************** #
# RULES

all: ${NAME}

${NAME}:${OBJS}
	${CC} ${CFLAGS} -I${INC} -o $@ $^
	@echo "$(NAME) compiled and ready to be tested!"
	@echo "Philosophers are ready to die!"

.c.o:
	${CC} ${CFLAGS} -I${INC} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	@echo "Everything cleaned up for $(NAME)!"

re: fclean all
