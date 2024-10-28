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
UTILS		=	u_handler.c \
				u_initialization.c \
				u_free.c
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

test: $(NAME)
	$(RM) tests/*.out
	leaks -atExit -- ./push_swap 4 3 7 2 -1 -3 6 8 > tests/ok_1.out \
	| leaks -atExit -- ./push_swap 7 +3 9 2 -1 -0 6 +8 > tests/ok_2.out \
	| leaks -atExit -- ./push_swap "4 2 1 3 -1 5 -6" > tests/ok_3.out \
	| leaks -atExit -- ./push_swap "   1    2    3    4   0 " > tests/ok_4.out \
	| leaks -atExit -- ./push_swap "1234" 1 3 4 5 > tests/ok_5.out \
	| leaks -atExit -- ./push_swap "1234" 000002 > tests/ok_6.out \
	| leaks -atExit -- ./push_swap " 1234" 1 3 4 5 > tests/ok_7.out \
	| leaks -atExit -- ./push_swap 1 > tests/no_1.out \
	| leaks -atExit -- ./push_swap 1 2 3 4 5 6 7 8 9 10 11 > tests/no_2.out \
	| leaks -atExit -- ./push_swap -+0 > tests/error_1.out \
	| leaks -atExit -- ./push_swap +-0 > tests/error_2.out \
	| leaks -atExit -- ./push_swap 1a > tests/error_3.out \
	| leaks -atExit -- ./push_swap "" > tests/error_4.out \
	| leaks -atExit -- ./push_swap " " > tests/error_5.out \
	| leaks -atExit -- ./push_swap 4+2 5 1 > tests/error_6.out \
	| leaks -atExit -- ./push_swap ++1 > tests/error_7.out \
	| leaks -atExit -- ./push_swap 2 "" 4 3 > tests/error_8.out \
	| leaks -atExit -- ./push_swap 2 " " 4 3 > tests/error_9.out \
	| leaks -atExit -- ./push_swap 42 000042 5 1 > tests/error_10.out \
	| leaks -atExit -- ./push_swap a b c d e f g h i j . - , > tests/error_11.out \
	| leaks -atExit -- ./push_swap 1 2 3 4 1 2 3 4 1 2 3 4 > tests/error_12.out \
	| leaks -atExit -- ./push_swap 1 2 3 4 a b c d 1a 2b 3c 4d > tests/error_13.out \
	| leaks -atExit -- ./push_swap -2147483649 2147483648 > tests/error_14.out \
	| leaks -atExit -- ./push_swap -4294967294 4294967294 > tests/error_15.out \
	| leaks -atExit -- ./push_swap -18446744073709551614 18446744073709551614 > tests/error_16.out \
	| leaks -atExit -- ./push_swap 1 2 3 4 a b c d 1a 2b 3c 4d > tests/error_17.out

.PHONY: all clean fclean re test