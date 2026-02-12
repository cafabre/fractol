# **************************************************************************** #
#                                 PROGRAM NAME                                 #
# **************************************************************************** #
NAME        = fractol

# **************************************************************************** #
#                                 CONFIG & FLAGS                               #
# **************************************************************************** #
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -MMD
RM          = rm -rf

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INC         = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC_DIR     = src
OBJ_DIR     = obj

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #
SRC_FILES   = main.c \
              fractol_init.c \
              fractol_draw.c \
              fractol_math.c \
              fractol_events.c \
              fractol_utils.c \
              fractol_validation.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS        = $(OBJS:.o=.d)

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all: $(NAME)

# Final binary compilation
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✨ Fract-ol compiled successfully!$(RESET)"

# Libft compilation
$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

# MLX compilation
$(MLX):
	@make -C $(MLX_DIR) --no-print-directory

# Object files compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Object directory creation
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object and dependency files
clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "$(RED)🧹 Objects and dependencies cleaned.$(RESET)"

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)🗑️  Everything removed.$(RESET)"

# Rebuild everything
re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re $(LIBFT) $(MLX)