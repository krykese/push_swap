NAME := push_swap.a
SOFT_NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g3

SRC = main.c \
	check_error.c \
	cost.c \
	operation_cost.c \
	push_and_swap.c \
	reverse_rotate.c \
	rotate.c \
	sort_algo.c \
	utils.c

OBJ := $(SRC:.c=.o)

all: $(NAME) $(SOFT_NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(SOFT_NAME):
	$(CC) $(CFLAGS) -o $(SOFT_NAME) $(NAME) $^

test3:
	$(eval ARG = $(shell shuf -i 0-50 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l


test5:
	$(eval ARG = $(shell shuf -i 0-50 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test9:
	$(eval ARG = $(shell shuf -i 0-50 -n 9))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100:
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

ttest100:
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
	./push_swap $(ARG)

test500:
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

ttest500:
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
	./push_swap $(ARG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(SOFT_NAME)

re: fclean all

.PHONY: all clean fclean re
