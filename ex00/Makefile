NAME	= rush-02

${NAME}:
		gcc -c -Wall -Wextra -Werror main.c ft_split.c process.c process1.c validate.c
		gcc -Wall -Wextra -Werror -o rush-02 main.c ft_split.c process.c process1.c validate.c


all:	${NAME}

clean:
		rm -rf main.o ft_split.o process.o process1.o validate.o

fclean:	clean
		rm -rf rush-02