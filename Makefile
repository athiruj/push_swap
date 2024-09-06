CC		= 	cc
CCFLAGS	= 	-Wall -Wextra -Werror
AR 		= 	ar -rsc
RM		= 	rm -rf

NAME 	= 	push_swap

HEADER 	= 	push_swap.h
FILE	=	push_swap.c
UTILS	=
OBJS	=	$(FILE:.c=.o) $(UTILS:.c=.o)

## BONUS ZONE
# BONUSNAME 		= 	checker

# BONUSHEADER 	= 	checker.h
# BONUSFILE		=	checker.c
# BONUSUTILS		=	
# BONUSOBJS		=	$(BONUSFILE:.c=.o) $(BONUSUTILS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c %(HEADER) Makefile
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re