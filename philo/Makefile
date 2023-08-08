NAME:=philo

SRC_DIR:=src
BUILD_DIR:=build

CFLAGS:=-g -fsanitize=thread -Wall -Wextra -Werror -Ilibft/include -Isrc
DEPFLAGS=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC:=$(shell find $(SRC_DIR) -name '*.c')
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
