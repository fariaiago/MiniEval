CC ?= gcc

NAME	= MiniEval
MAIN	= main.c

CFLAGS	= -Wall -g -o $(NAME)

all:
	$(CC) $(MAIN) $(CFLAGS)

run:
	./$(NAME) < input.txt

.PHONY: run