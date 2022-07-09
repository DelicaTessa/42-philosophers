# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tclement <tclement@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/09 19:21:22 by tclement      #+#    #+#                  #
#    Updated: 2022/04/21 13:42:41 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC_DIR = 	$(shell find includes -type d)

##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)

##Folder where he will store the .o
OBJ_DIR	= obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##Add to the vpath the folder find in SRC_DIR
vpath %.h $(foreach dir, $(INC_DIR), $(dir):)

##List every .c found inside SRC_DIR
SRC = philo.c death.c init.c routine.c lib.c utils.c eat.c main.c print.c

##List every .h found inside INC_DIR
INC = philo.h

##Transform and place every .o from SRC
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##Basics flags
CFLAGS =	-Wall -Wextra -Werror #-g3 -fsanitize=thread

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I $(dir))

##Define the compiler to use
CC =	gcc

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
				@echo "Compiling $(NAME) ...\c"
				$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) -lpthread -o philo
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir -p $(OBJ_DIR)
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all bonus clean fclean re
