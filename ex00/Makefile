NAME = easy_find

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

IFLAGS = easyfind.hpp

SRCS = main.cpp

DIR_OBJ := .object/

OBJS = $(patsubst %.cpp, ${DIR_OBJ}%.o, ${SRCS})

all: $(NAME)

$(NAME): $(SRCS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


${DIR_OBJ}%.o: %.cpp $(IFLAGS) Makefile
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONE: all clean fclean re
