CC			= 	cc
# CCFLAGS		= 	-Wall -Wextra -Werror
CCFLAGS		=	
AR 			= 	ar -rsc
RM			= 	rm -rf

NAME 		= 	push_swap

LIB_DIR		=	libft/
LIBFT		=	libft/libft.a

OBJS_DIR	=	odjs/

HEADER		= 	push_swap.h
FILES		=	push_swap.c
UTILS		=	u_input_handler.c \
				u_initial_stack.c
OPERS		=	
# OPERS		=	o_swap.c \
# 				o_sswap.c \
# 				o_push.c \ 
# 				o_rotate.c \
# 				o_rrotate.c \
# 				o_reverse_rotate.c \ 
# 				o_rreverse_rotate.c 

FILE_OBJS	=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(UTILS:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(OPERS:.c=.o)) \

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