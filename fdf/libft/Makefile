# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaollier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 15:54:41 by gaollier          #+#    #+#              #
#    Updated: 2023/11/15 15:55:57 by gaollier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

## SRCS

LIST_SRC = ft_atoi.c \
	ft_atoi_base.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi_base.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstmap.c

LIST_SRC += ft_printf.c \
	print_int.c \
	print_low_hex.c \
	print_ptr.c \
	print_str.c \
	print_unsigned_dec.c \
	print_up_hex.c

LIST_SRC +=	get_next_line.c \
	get_next_line_utils.c

DIR_SRC += src/
DIR_SRC += src/libft_src/
DIR_SRC += src/ft_printf/
DIR_SRC += src/gnl/

vpath %.c $(DIR_SRC)
# Virtual Path -> indique au Makefile de faire matcher des .c avec un prefix contenu dans DIR_SRC
## OBJS
DIR_BUILD = .build/
OBJ = $(patsubst %.c, $(DIR_BUILD)/%.o, $(LIST_SRC))
#patsubst -> pattern substitution: Cherche dans LIST_SRC tous les fichiers .c, les transforme en .o
# OBJ = $(LIST_SRC:.c=.o) #### Remplace les .c par des .o

## HEADERS

DIR_HEADER = includes/

LIST_HEADER = libft.h	\
	ft_printf.h			\
	get_next_line.h		\
	stack.h 			\

vpath %.h $(LIST_HEADER)

# Shortcuts
# SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
# OBJ := $(addprefix $(DIR_BUILD), $(OBJ)) #### Ajoute le prefix DOSSIER avant les .o
# HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))

CC = cc
CFLAGS = -Wall -Wextra -Werror

# .PHONY: all
all: $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(DIR_BUILD)/%.o: %.c
	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -o $@

# $(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEADER)
# 	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -o $@

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

# .PHONY: clean
clean:
	$(RM) -r $(DIR_BUILD)

# .PHONY: fclean
fclean:	clean
	$(RM) $(NAME)

# .PHONY: re
re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re
