# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaollier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 15:59:02 by gaollier          #+#    #+#              #
#    Updated: 2023/11/15 16:00:01 by gaollier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############
### NAME ###
############

NAME = fdf

###############
### SOURCES ###
###############

DIR_SRC += src/
DIR_SRC += src/vertex/

LIST_SRC += main.c
LIST_SRC +=	readnstore_elements.c
LIST_SRC +=	free_fcts.c
LIST_SRC += displays.c
LIST_SRC += matrixs_matching.c
LIST_SRC += draw_points.c

# LIST_SRC += draw_point.c

vpath %.c $(DIR_SRC)

###############
### OBJECTS ###
###############

DIR_BUILD = .build/

# LIST_OBJ = $(LIST_SRC:.c=.o)

OBJ = $(patsubst %.c, $(DIR_BUILD)/%.o, $(LIST_SRC))

###############
### HEADERS ###
###############

DIR_HEADER += includes/

LIST_HEADER += fdf.h
LIST_HEADER += libft.h
LIST_HEADER += ft_printf.h
LIST_HEADER += gnl.h
LIST_HEADER += mlx.h

# variable notee en bleu

vpath %.h $(DIR_HEADER)

###########
### LIB ###
###########

DIR_LIBFT = libft/
DIR_MLX = minilibx-linux/

INCLUDES_LIB += -I $(DIR_HEADER)
INCLUDES_LIB += -I $(DIR_LIBFT)/includes/
INCLUDES_LIB += -I $(DIR_MLX)

#$(addprefix $(DIR_LIB), libft/)

# Shortcuts
# SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
# OBJ = $(addprefix $(DIR_BUILD), $(LIST_OBJ))
# HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))

MLX = $(addprefix $(DIR_MLX), libmlx.a)

#LIBFT = $(addprefix $(DIR_LIBFT), libft.a)
LIBFT = $(DIR_LIBFT)/libft.a
# (LIBFT = $(DIR_LIBFT)/libft.a) == (LIBFT = $(addprefix $(DIR_LIBFT), libft.a))

###################
### COMPILATION ###
###################

CC = cc
CFLAGS = -Wall -Wextra

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifneq ($(no_error), true)
	CFLAGS += -Werror
endif
# option a rajouter au moment du make ex: make debug=true
#  //                                 ex: make no_error=true
# ifeq (si c'est egal) si debug egal true alors aux CFLAGS += on ajoute -fsanitize=adress, fait attention au comportement indefinis
# -g3 pouur afficher plus d'info sur le code et la localisation des erreurs.
# finir par endif

##### RULES #####

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz


$(OBJ): $(DIR_BUILD)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c $(INCLUDES_LIB) -o $@
####$(CC) $(CFLAGS) $< -c $(INCLUDES_LIB) -o $@
$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(MLX):
	$(MAKE) -C $(DIR_MLX)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

clean:
	$(RM) -r $(DIR_BUILD)
	$(MAKE) -C $(DIR_MLX) clean
	$(MAKE) -C $(DIR_LIBFT) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re
