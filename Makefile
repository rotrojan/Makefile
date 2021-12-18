# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2021/12/18 23:48:45 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_class

SRCS =	main.cpp		\
		Animal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		WrongCat.cpp	\
		WrongAnimal.cpp	\
		Brain.cpp		\

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

SRCS_DIR = srcs
OBJS_DIR = .objs
INCLUDES_DIR = includes

MAKE = make
MAKEFLAGS += --no-print-directory
CXX = c++
RM = rm -f
MKDIR = mkdir -p
DEBUG = 0
ifeq ($(shell test -f $(OBJS_DIR)/debug1; echo $$?), 0)
	DEBUG = 1
endif
SANITIZE = 0
ifeq ($(shell test -f $(OBJS_DIR)/sanitize1; echo $$?), 0)
	SANITIZE = 1
endif

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic
ifeq ($(DEBUG), 1)
	CXXFLAGS += -g3
endif
ifeq ($(SANITIZE), 1)
	CXXFLAGS += -fsanitize=address
endif
LDFLAGS = $(LIBS:%=-L lib%)
LDLIBS = $(LIBS:%=-l%)

vpath %.cpp ./ $(shell find $(SRCS_DIR) -type d)

YELLOW = \033[33m
GREEN = \033[32m
BOLD = \033[1m
NO_BOLD = \033[21m
ERASE = \r\033[K
ESC_STOP = \033[0m

COMPILING_PRINTED = 0
VARIABLES_PRINTED = 0
VARIABLES_INTERLINE_PRINTED = 0
PRINT_INTERLINE = printf '$(YELLOW)$(BOLD)================================================================================$(ESC_STOP)\n'

all: display_variables $(NAME)

$(NAME): $(OBJS)
	@$(PRINT_INTERLINE)
	@printf '$(YELLOW)$(BOLD)linking object files$(ESC_STOP)\n'
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@$(PRINT_INTERLINE)
	@printf '$(YELLOW)$(BOLD)%s$(NO_BOLD) built$(ESC_STOP)\n' '$@'
	@$(PRINT_INTERLINE)

$(OBJS): $(OBJS_DIR)/%.o: %.cpp $(OBJS_DIR)/debug$(DEBUG) $(OBJS_DIR)/sanitize$(SANITIZE) | $(OBJS_DIR)
	@if [ '$(COMPILING_PRINTED)' -eq '0' ]; then \
		if [ '$(VARIABLES_INTERLINE_PRINTED)' -eq '0' ]; then \
			$(PRINT_INTERLINE); \
		fi; \
		printf '$(BOLD)$(YELLOW)compiling sources$(ESC_STOP)\n'; \
	fi; $(eval COMPILING_PRINTED = 1)
	@printf '%s' $@
	@$(CXX) $(CXXFLAGS) $(INCLUDES_DIR:%=-I %) -c $< -o $@
	@printf '$(ERASE)$(GREEN)%s$(ESC_STOP)\n' $@

$(OBJS_DIR):
	@$(MKDIR) $@

$(OBJS_DIR)/debug$(DEBUG): | $(OBJS_DIR)
	@$(RM) $(OBJS_DIR)/debug*
	@touch $@

$(OBJS_DIR)/sanitize$(SANITIZE): | $(OBJS_DIR)
	@$(RM) $(OBJS_DIR)/sanitize*
	@touch $@

display_variables:
	@if [ '$(VARIABLES_PRINTED)' -eq '0' ]; then \
		$(PRINT_INTERLINE); \
		printf '$(YELLOW)building $(BOLD)%s$(ESC_STOP)\n' '$(NAME)'; \
		printf '$(YELLOW)compiler:$(ESC_STOP) %s\n' '$(CXX)'; \
		printf '$(YELLOW)compilation flags:$(ESC_STOP) %s\n' '$(CXXFLAGS)'; \
		printf '$(YELLOW)libraries:$(ESC_STOP) %s\n' '$(LIBS)'; \
		printf '$(YELLOW)linking flags:$(ESC_STOP) %s\n' '$(LDFLAGS)'; \
		$(PRINT_INTERLINE); \
	fi; $(eval VARIABLES_PRINTED = 1) $(eval VARIABLES_INTERLINE_PRINTED = 1)

clean:
	@$(RM) -r $(OBJS_DIR)
	@printf '%s removed\n' '$(OBJS_DIR)'

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@printf '%s removed\n' '$(NAME)'

re: fclean all

-include $(DEPENDENCIES)
.PHONY: all clean fclean re display_variables
