NAME 		= ex00
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRCS_NAME	=	main.cpp \
				Bureaucrat.cpp

SRCS_DIR 	= ./srcs/

#OBJS
OBJS_DIR 	= ./objs/
OBJ			= ${SRCS_NAME:.cpp=.o}
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))

#HEADER
HEADER_INC	=	-I./includes/

DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS_NAME:.cpp=.d))

RED 		=	\033[0;31m
GREEN 		=	\033[0;32m
NONE 		=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\t\t[ $(GREEN)✓$(NONE) ] $(GREEN)$(NAME)$(NONE) ready!"

run: all
	@./$(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADER_INC) -o $@ -c $<

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\t\t[ $(RED)✗$(NONE) ] objs/ directory"

fclean: clean
	@rm -f $(NAME)
	@echo "\t\t[ $(GREEN)✓$(NONE) ] Project $(GREEN)$(NAME)$(NONE) clean"

re: fclean all

.PHONY: all clean fclean re header

-include ${DEPS}