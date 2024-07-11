#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 20:20:04 by maurodri          #+#    #+#              #
#    Updated: 2024/07/11 19:54:46 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := push_swap
LIBFT_DIR := ./lib/libftx
LIBFT := $(LIBFT_DIR)/libft.a
FILES := main.c \
	push_swap.c \
	two_stks.c \
	two_stks_push.c \
	two_stks_revrotate.c \
	two_stks_rotate.c \
	two_stks_swap.c \
	psargs.c \
	sort3b.c \
	sort3b_partition.c \
	sort3b_return.c \
	sort3b_le4.c \
	stat3b.c \
	item.c

OBJ_DIR := ./obj/
MANDATORY_OBJS := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(FILES)))
BONUS_OBJS := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(BONUS_FILES)))
DEP_FLAGS := -MP -MD
VPATH := ./
CFLAGS := -g3 -Wall -Wextra -Werror 
CC := cc

INCLUDES := -I./ -I$(LIBFT_DIR)/includes
OBJS := $(MANDATORY_OBJS)
ETAGS_BASE := ./

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@
	etags $$(find $(ETAGS_BASE) -name '*.[ch]') $$(find $(LIBFT_DIR) -name '*.[ch]') --include '~/glibc/TAGS'

$(OBJS): $(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS) -o $@ -c $< $(INCLUDES) 

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus

clean:
	rm -fr $(OBJ_DIR) **/*~ *~ **/.#*
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
