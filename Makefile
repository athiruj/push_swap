CC			= 	cc
CCFLAGS		= 	-Wall -Wextra -Werror
# CCFLAGS		=	
AR 			= 	ar -rsc
RM			= 	rm -rf

NAME 		= 	push_swap

LIB_DIR		=	libft/
LIBFT		=	libft/libft.a

OBJS_DIR	=	odjs/

HEADER		= 	push_swap.h
FILES		=	push_swap.c
SORTS		=	s_case.c \
				s_find.c  
				s_sort.c \
				s_sort_case.c

UTILS		=	u_checker.c \
				u_initialization.c \
				u_free.c \
				u_utils.c  

OPERS		=	o_push.c \
				o_swap.c \
				o_rotate.c \
				o_reverse_rotate.c 

FILE_OBJS	=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o)) \
				$(addprefix $(OBJS_DIR), $(SORTS:.c=.o)) \
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

tclean:
	$(RM) tests/*.txt

test: all tclean ok1 ok2 ok3 ok4 ok5 ok6 ok7 ok8 ok9 ok10 no1 no2 error1 error2 error3 error4 error5 error6 error7 error8 error9 error10 error11 error12 error13 error14 error15 error16 error17

ok1: $(NAME)
	leaks -atExit -- ./push_swap 4 3 7 2 -1 -3 6 8 > tests/ok_1.txt

ok2: $(NAME)
	leaks -atExit -- ./push_swap 7 +3 9 2 -1 -0 6 +8 > tests/ok_2.txt

ok3: $(NAME)
	leaks -atExit -- ./push_swap "4 2 1 3 -1 5 -6" > tests/ok_3.txt

ok4: $(NAME)
	leaks -atExit -- ./push_swap "   1    2    3    4   0 " > tests/ok_4.txt

ok5: $(NAME)
	leaks -atExit -- ./push_swap "1234" 1 3 4 5 > tests/ok_5.txt

ok6: $(NAME)
	leaks -atExit -- ./push_swap "1234" 000002 > tests/ok_6.txt

ok7: $(NAME)
	leaks -atExit -- ./push_swap " 1234" 1 3 4 5 > tests/ok_7.txt

ok8: $(NAME)
	leaks -atExit -- ./push_swap "+000001234" -000002 > tests/ok_8.txt

ok9: $(NAME)
	leaks -atExit -- ./push_swap "+000001234 4" -000002 > tests/ok_9.txt

ok10: $(NAME)
	leaks -atExit -- ./push_swap 500 499 498 497 496 495 494 493 492 491 490 489 488 487 486 485 484 483 482 481 480 479 478 477 476 475 474 473 472 471 470 469 468 467 466 465 464 463 462 461 460 459 458 457 456 455 454 453 452 451 450 449 448 447 446 445 444 443 442 441 440 439 438 437 436 435 434 433 432 431 430 429 428 427 426 425 424 423 422 421 420 419 418 417 416 415 414 413 412 411 410 409 408 407 406 405 404 403 402 401 400 399 398 397 396 395 394 393 392 391 390 389 388 387 386 385 384 383 382 381 380 379 378 377 376 375 374 373 372 371 370 369 368 367 366 365 364 363 362 361 360 359 358 357 356 355 354 353 352 351 350 349 348 347 346 345 344 343 342 341 340 339 338 337 336 335 334 333 332 331 330 329 328 327 326 325 324 323 322 321 320 319 318 317 316 315 314 313 312 311 310 309 308 307 306 305 304 303 302 301 300 299 298 297 296 295 294 293 292 291 290 289 288 287 286 285 284 283 282 281 280 279 278 277 276 275 274 273 272 271 270 269 268 267 266 265 264 263 262 261 260 259 258 257 256 255 254 253 252 251 250 249 248 247 246 245 244 243 242 241 240 239 238 237 236 235 234 233 232 231 230 229 228 227 226 225 224 223 222 221 220 219 218 217 216 215 214 213 212 211 210 209 208 207 206 205 204 203 202 201 200 199 198 197 196 195 194 193 192 191 190 189 188 187 186 185 184 183 182 181 180 179 178 177 176 175 174 173 172 171 170 169 168 167 166 165 164 163 162 161 160 159 158 157 156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 > tests/ok_10.txt

no1: $(NAME)
	leaks -atExit -- ./push_swap 1 > tests/no_1.txt

no2: $(NAME)
	leaks -atExit -- ./push_swap 1 2 3 4 5 6 7 8 9 10 11 > tests/no_2.txt

error1: $(Name)
	leaks -atExit -- ./push_swap -+0 > tests/error_1.txt

error2: $(Name)
	leaks -atExit -- ./push_swap +-0 > tests/error_2.txt

error3: $(Name)
	leaks -atExit -- ./push_swap 1a > tests/error_3.txt

error4: $(Name)
	leaks -atExit -- ./push_swap "" > tests/error_4.txt

error5: $(Name)
	leaks -atExit -- ./push_swap " " > tests/error_5.txt

error6: $(Name)
	leaks -atExit -- ./push_swap 4+2 5 1 > tests/error_6.txt

error7: $(Name)
	leaks -atExit -- ./push_swap ++1 > tests/error_7.txt

error8: $(Name)
	leaks -atExit -- ./push_swap 2 "" 4 3 > tests/error_8.txt

error9: $(Name)
	leaks -atExit -- ./push_swap 2 " " 4 3 > tests/error_9.txt

error10: $(Name)
	leaks -atExit -- ./push_swap 42 000042 5 1 > tests/error_10.txt

error11: $(Name)
	leaks -atExit -- ./push_swap a b c d e f g h i j . - , > tests/error_11.txt

error12: $(Name)
	leaks -atExit -- ./push_swap 1 2 3 4 1 2 3 4 1 2 3 4 > tests/error_12.txt

error13: $(Name)
	leaks -atExit -- ./push_swap 1 2 3 4 a b c d 1a 2b 3c 4d > tests/error_13.txt

error14: $(Name)
	leaks -atExit -- ./push_swap -2147483649 2147483648 > tests/error_14.txt

error15: $(Name)
	leaks -atExit -- ./push_swap -4294967294 4294967294 > tests/error_15.txt

error16: $(Name)
	leaks -atExit -- ./push_swap -18446744073709551614 18446744073709551614 > tests/error_16.txt

error17: $(Name)
	leaks -atExit -- ./push_swap 1 2 3 4 a b c d 1a 2b 3c 4d > tests/error_17.txt

.PHONY: all clean fclean re tclean test ok1 ok2 ok3 ok4 ok5 ok6 ok7 ok8 ok9 ok10 no1 no2 error1 error2 error3 error4 error5 error6 error7 error8 error9 error10 error11 error12 error13 error14 error15 error16 error17