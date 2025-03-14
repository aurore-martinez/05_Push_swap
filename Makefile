# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:19:31 by aumartin          #+#    #+#              #
#    Updated: 2024/09/11 10:51:59 by aumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

V = false

ifeq ($(V),true)
    ECHO =
else
    ECHO = @
endif

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT = Libft/libft.a
SRC = main.c utils.c stack.c error_management.c \
	moves/swaps.c moves/pushes.c moves/rotates.c moves/reverse_rotates.c \
	sort/big_stack.c sort/small_stack.c sort/utils.c moves/moves_utils.c
OBJ = $(SRC:.c=.o)

# Séquences d'échappement ANSI pour les couleurs
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

# Symboles Unicode
CHECK_MARK = ✔
UNCHECKED_MARK = ✘
COMP_SUCCESS = $(GREEN)$(CHECK_MARK)$(RESET)
COMP_FAILURE = $(RED)$(UNCHECKED_MARK)$(RESET)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation de push_swap en cours..."
	@$(ECHO)make -C Libft --silent --no-print-directory \
	&& { echo "Compilation de la Libft ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de la Libft échouée ($(COMP_FAILURE))" ; exit 1; }
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) \
	&& { echo "$(NAME) a été créé avec succès ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de $(NAME) échouée ($(COMP_FAILURE))" ; exit 1; }
	@echo "Compilation réussie, Aurore ($(COMP_SUCCESS))"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(ECHO)make clean -C Libft --silent --no-print-directory
	$(ECHO)rm -f $(OBJ)
	@echo "Nettoyage réussi, Aurore ($(COMP_SUCCESS))"

fclean: clean
	$(ECHO)rm -f $(NAME)
	$(ECHO)rm -f Libft/libft.a
	@echo "Nettoyage complet réussi, Aurore ($(COMP_SUCCESS))"

re: fclean all

.PHONY: all clean fclean re

