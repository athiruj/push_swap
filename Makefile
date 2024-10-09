CC			= 	cc
CCFLAGS		= 	
# CCFLAGS		= 	-Wall -Wextra -Werror
AR 			= 	ar -rsc
RM			= 	rm -rf

NAME 		= 	push_swap

LIB_DIR		=	libft/
LIBFT		=	libft/libft.a

UTILS_DIR	=	utils/
OPERS_DIR	=	operations/
OBJS_DIR	=	odjs/

HEADER		= 	push_swap.h
FILES		=	push_swap.c
UTILS		=	idk.c
OPERS		=	swap.c sswap.c push.c rotate.c rrotate.c reverse_rotate.c rreverse_rotate.c

FILE_OBJS	=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o))
UTIL_OBJS	=	$(addprefix $(OBJS_DIR)$(UTILS_DIR), $(UTILS:.c=.o))
OPER_OBJS	=	$(addprefix $(OBJS_DIR)$(OPERS_DIR), $(OPERS:.c=.o))

## BONUS ZONE
# BONUSNAME 		= 	checker

# BONUSHEADER 	= 	checker.h
# BONUSFILE		=	checker.c
# BONUSUTILS		=	
# BONUSOBJS		=	$(BONUSFILE:.c=.o) $(BONUSUTILS:.c=.o)

all: makelib $(NAME) $(HEADER)

$(NAME): $(FILE_OBJS) $(UTIL_OBJS) $(OPER_OBJS) $(LIBFT) $(HEADER) Makefile 
	$(AR) $@ $(FILE_OBJS) $(UTIL_OBJS) $(OPER_OBJS)

$(UTILS_DIR): $(OBJS_DIR)
		@mkdir $(OBJS_DIR)$@

$(OPERS_DIR): $(OBJS_DIR)
		@mkdir $(OBJS_DIR)$@

$(OBJS_DIR):
		@mkdir -p $@

$(FILE_OBJS): $(FILES) $(OBJS_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@  -I $(HEADER)

$(OBJS_DIR)$(UTILS_DIR)%.o: $(UTILS_DIR)%.c $(UTILS_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@  -I $(HEADER)

$(OBJS_DIR)$(OPERS_DIR)%.o: $(OPERS_DIR)%.c $(OPERS_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(HEADER)

makelib:
	@make -C $(LIB_DIR) --no-print-directory

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re