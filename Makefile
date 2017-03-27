##
## Makefile for Makefile in /home/TAN_S/PSU_2016_navy
## 
## Made by Sébastien TAN
## Login   <TAN_S@epitech.net>
## 
## Started on  Mon Jan 30 12:05:48 2017 Sébastien TAN
## Last update Thu Feb 16 17:40:47 2017 Sébastien TAN
##

CFLAGS	= -Wall -Wextra

CFLAGS	+= -I include

CC	= gcc

RM	= rm -f

NAME	= navy

SRC	= src/main.c \
	  src/get_next_line.c \
	  src/error.c \
	  src/check_pos.c \
	  src/my_getnbr.c \
	  src/my_getnbr_base.c \
	  src/fct.c \
	  src/makemap.c \
	  src/player1.c \
	  src/player2.c \
	  src/disp_map.c \
	  src/send_signal.c \
	  src/send_signal_2.c \
	  src/my_putnbr.c \
	  src/wait_player2.c \
	  src/receive_signal.c \
	  src/touched_and_wait.c \
	  src/convertisor_reverse.c \
	  src/help.c \
	  src/connected_or_not.c \
	  src/send_signal_1_5.c

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
