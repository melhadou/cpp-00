NAME = bank
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = Account.cpp tests.cpp
OBJ = $(CPPFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
