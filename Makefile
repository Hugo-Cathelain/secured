##
## EPITECH PROJECT, 2024
## B-CPE-110-LYN-1-1-secured-hugo.cathelain
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2023
## myls
## File description:
## Makefile
##

SRC =	src/secured.c \
		src/table.c \
		src/shared/my_putstr.c \
		src/shared/my_strlen.c \

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

NAME = libhastable.a

FLAGS = -Wall -Wextra

FLAG_T = -Iinclude --coverage -lcriterion

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rcs $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	gcc -o unit_tests tests/testing.c $(SRC) $(FLAG_T)
	make clean
	./unit_tests && gcovr -e tests/ && gcovr -e tests/ -b
