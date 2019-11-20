NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I$(INC_PATH)

SRC_PATH = ./srcs
LIB_PATH = ./lib
INC_PATH = ./include
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME = ft_printf.c \
		check.c \
		tab_utils.c \
		print_and_count_utils.c \
		print_c.c \
		print_s.c \
		print_p.c \
		print_d.c \
		print_u.c \
		print_x.c \
		print_percent.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = ft_isdigit.c \
		ft_strlen.c \
		ft_itoa_base_bonus.c \
		ft_utoa_base.c
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/, $(OBJLIB_NAME))

all : $(NAME)

$(NAME) : $(OBJ) $(OBJLIB)
	@ar rcs $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	@rm -rf ./obj $(NAME)

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)

.PHONY: all clean fclean re norm
