NAME:=philo

SRC_DIR:=src
BUILD_DIR:=build

CFLAGS:=-Wall -Wextra -Werror -Ilibft/include -Isrc
DEPFLAGS=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC:=	src/main.c \
		src/args/args.c \
		src/error/error.c \
		src/minilibft/ft_atol.c \
		src/minilibft/ft_isdigit.c \
		src/minilibft/ft_isspace.c \
		src/minilibft/ft_strlen.c \
		src/thread/destroy.c \
		src/thread/log.c \
		src/thread/monitor.c \
		src/thread/routine.c \
		src/thread/shared_data.c \
		src/thread/start.c \
		src/thread/wait.c \
		src/util/math.c \
		src/util/safe_rw.c \
		src/util/swap.c \
		src/util/time.c
OBJ:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC))

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

-include $(DEP)
