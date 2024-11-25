CC			=	cc
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar -src
RM			=	rm -rf

SRCSFILE 	= 	get_next_line.c \
				get_next_line_utils.c
			
OBJS 		=	$(SRCSFILE:.c=.o)

HEADER 		= 	get_next_line.h
NAME 		=	get_next_line.a

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
