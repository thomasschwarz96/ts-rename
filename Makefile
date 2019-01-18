CC = gcc
DIR = /usr/local/bin/
NAME = ts-rename
OBJ = main.c helpers.c helpers.h

install:
	$(CC) -o $(NAME) $(OBJ)
	cp $(NAME) $(DIR) 

uninstall:
	rm -f $(DIR)$(NAME)

