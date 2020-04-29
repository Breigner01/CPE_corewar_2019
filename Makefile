##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

MAKEFLAGS	+=	--no-print-directory

LFLAGS	=

CFLAGS	+=	-Wall -Wextra

CPPFLAGS =	-I./include

TFLAGS	=	-lcriterion --coverage

NAME	=	corewar

SRC		=	src/operations.c \
			src/util/hash.c

MAIN 	=	src/main.c

MOBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

ifdef DEBUG
  CFLAGS += -ggdb3 -DDEBUG
endif

%.o:	%.c
	@echo -e -n "\033[92m[ OK ]\033[0m"
	@echo "" $<
	@gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo "*.o"
	@rm -f $(OBJ) $(MOBJ)

fclean: clean
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re