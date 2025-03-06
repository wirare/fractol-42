include Sources.mk
NAME			:= fractol

DIR_LIB			:= lib
DIR_HEADERS     := headers
DIR_SOURCES     := srcs
DIR_OBJS        := .objs

DIR_MLX         := $(DIR_LIB)/MacroLibX
MLX_INCLUDES    := $(DIR_MLX)/includes
MLX             := $(DIR_MLX)/libmlx.so

OBJS            := $(addprefix $(DIR_OBJS)/, $(FRAC_SOURCES:%.c=%.o))

CC              := cc
CFLAGS          := -Wall -Wextra -Werror -g
IFLAGS          := -I $(DIR_HEADERS) -I $(MLX_INCLUDES)

GREEN            = \033[0;32m
RED              = \033[0;31m
END              = \033[0m
DIR_DUP          = mkdir -p $(@D)


all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) -lm -lSDL2 $(OBJS) -o $(NAME) $(MLX) 
	@printf "$(GREEN)$(NAME) compiled$(END)\n"

$(MLX):
	$(MAKE) -C $(DIR_MLX) --no-print-directory -j

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJS)
	@printf "$(RED)$(NAME) cleaned objs$(END)\n"

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(DIR_MLX) fclean
	@printf "$(RED)$(NAME) removed$(END)\n"

re: fclean all

.PHONY: clean fclean re all
