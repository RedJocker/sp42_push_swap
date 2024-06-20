#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 20:20:04 by maurodri          #+#    #+#              #
#    Updated: 2024/06/19 21:30:47 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := push_swap
LIBFT_DIR := ./lib/libftx
LIBFT := $(LIBFT_DIR)/libft.a
FILES := push_swap.c \
	two_stks.c \
	psargs.c

# BONUS_FILES := main_bonus.c \
# 			envp_bonus.c \
# 			util_bonus.c \
# 			command_bonus.c \
# 			command_build_bonus.c \
# 			command_build_util_bonus.c \
# 			command_pipe_bonus.c \
# 			command_pipe_set_io_bonus.c \
# 			command_simple_bonus.c \
# 			command_simple_execute_bonus.c \
# 			io_handler_bonus.c

OBJ_DIR := ./obj/
MANDATORY_OBJS := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(FILES)))
BONUS_OBJS := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(BONUS_FILES)))
DEP_FLAGS := -MP -MD
VPATH := ./ ./mandatory ./bonus
CFLAGS := -g3 -Wall -Wextra -Werror 
CC := cc

ifdef WITH_BONUS
	INCLUDES := -I./ -I$(LIBFT_DIR)/includes
	CLEAR := $(MANDATORY_OBJS) $(patsubst %.o, %.d, $(MANDATORY_OBJS))
	OBJS := $(BONUS_OBJS)
	ETAGS_BASE := ./
	DEP_FILES := $(patsubst %.o, %.d, $(OBJS))
else
	INCLUDES := -I./ -I$(LIBFT_DIR)/includes
	CLEAR := $(BONUS_OBJS) $(patsubst %.o, %.d, $(BONUS_OBJS))
	OBJS := $(MANDATORY_OBJS)
	ETAGS_BASE := ./
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	rm -f $(CLEAR)	
	$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@
	etags $$(find $(ETAGS_BASE) -name '*.[ch]') $$(find $(LIBFT_DIR) -name '*.[ch]') --include '~/glibc/TAGS'

$(OBJS): $(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS) -o $@ -c $< $(INCLUDES) 

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	rm -fr $(OBJ_DIR) **/*~ *~ **/.#*
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

test_build: two_stks.c psargs.c $(LIBFT) 
	echo $(INCLUDES)
	$(CC) $(CFLAGS) test.c $^ $(INCLUDES) -o test

test: test_build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

-include $(DEP_FILES)
