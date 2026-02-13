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

# $(NAME) dépend des fichiers .a et des .o
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✨ Fract-ol compiled successfully!$(RESET)"

# Règle pour compiler la Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Règle UNIQUE pour la MinilibX
$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "📥 Cloning MinilibX..."; \
		git clone --depth 1 https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@echo "🛠️  Compiling MinilibX..."
	@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# --- CLEAN RULES ---

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) clean -C $(MLX_DIR) --no-print-directory; fi
	@echo "$(RED)🧹 Objects and dependencies cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	@$(RM) $(MLX_DIR)
	@echo "$(RED)🗑️  Everything removed.$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re