CC			= 	cc
CCFLAGS		= 	-Wall -Wextra -Werror
AR 			= 	ar -rsc
RM			= 	rm -rf

NAME 		= 	push_swap

LIB_DIR		=	libft/
LIBFT		=	libft/libft.a

OBJS_DIR	=	odjs/

HEADER		= 	push_swap.h
FILES		=	push_swap.c

SORTS		=	s_case.c \
				s_find.c \
				s_sort.c \
				s_sort_case.c

UTILS		=	u_free.c \
				u_utils.c \
				u_checker.c \
				u_initialization.c

OPERS		=	o_push.c \
				o_swap.c \
				o_rotate.c \
				o_reverse_rotate.c 

FILE_OBJS	=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(SORTS:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(UTILS:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(OPERS:.c=.o))

## BONUS ZONE
# BONUSNAME 		= 	checker

# BONUSHEADER 	= 	checker.h
# BONUSFILE		=	checker.c
# BONUSUTILS		=	
# BONUSOBJS		=	$(BONUSFILE:.c=.o) $(BONUSUTILS:.c=.o)

all: makelib $(NAME) $(HEADER)

$(NAME): $(OBJS_DIR) $(FILE_OBJS) $(LIBFT) $(HEADER) Makefile 
	$(CC) $(CCFLAGS) -o $@ $(FILE_OBJS) $(LIBFT)

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)%.o: %.c
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@  

makelib:
	@make -C $(LIB_DIR) --no-print-directory

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re