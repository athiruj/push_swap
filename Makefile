CC			= 	cc
CCFLAGS		= 	-Wall -Wextra -Werror
AR 			= 	ar -rsc
RM			= 	rm -rf

NAME 		= 	push_swap

LIB_DIR		=	libft/
LIBFT		=	libft/libft.a

GNL_DIR		=	get_next_line/
GNL			=	get_next_line/get_next_line.a

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

# BONUS ZONE
BONUSNAME 		= 	checker

BONUSOBJS_DIR	=	bonus_objs/

BONUSFILES		=	checker.c

BONUS_OBJS		=	$(addprefix $(BONUSOBJS_DIR), $(BONUSFILES:.c=.o)) \
					$(addprefix $(BONUSOBJS_DIR), $(addprefix $(BONUSGNL_DIR), $(BONUSGNLFILES:.c=.o))) \
					$(addprefix $(BONUSOBJS_DIR), $(UTILS:.c=.o)) \
					$(addprefix $(BONUSOBJS_DIR), $(OPERS:.c=.o))

all: makelib $(NAME) $(HEADER)

bonus: all makegnl $(BONUSNAME) $(HEADER)

$(NAME): $(OBJS_DIR) $(FILE_OBJS) $(LIBFT) $(HEADER) Makefile 
	$(CC) $(CCFLAGS) -o $@ $(FILE_OBJS) $(LIBFT)

$(BONUSNAME): $(BONUSOBJS_DIR) $(BONUS_OBJS) $(LIBFT) $(GNL) $(HEADER) Makefile 
	$(CC) $(CCFLAGS) -o $@ $(BONUS_OBJS) $(LIBFT) $(GNL)

$(OBJS_DIR):
	@mkdir -p $@

$(BONUSOBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)%.o: %.c
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@ 

$(BONUSOBJS_DIR)%.o: %.c
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@

makelib:
	@make -C $(LIB_DIR) --no-print-directory

makegnl:
	@make -C $(GNL_DIR) --no-print-directory

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJS_DIR) $(BONUSOBJS_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(GNL_DIR)
	$(RM) $(NAME) $(BONUSNAME)

re: clean all

.PHONY: all clean fclean re bonus