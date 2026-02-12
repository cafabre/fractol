# **************************************************************************** #
#                                 LIBRARY NAME                                 #
# **************************************************************************** #
NAME        = libft.a

# **************************************************************************** #
#                                 CONFIG & FLAGS                               #
# **************************************************************************** #
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -MMD
AR          = ar rcs
RM          = rm -rf

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #
OBJ_DIR     = obj

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #
# Chars files
CHAR_DIR   = char/
CHAR_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
              ft_isprint.c ft_isspace.c ft_toupper.c ft_tolower.c

# Strings files
STR_DIR     = string/
STR_FILES   = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
              ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_strnstr.c \
              ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
              ft_split.c ft_strmapi.c ft_striteri.c

# Memory files
MEM_DIR     = memory/
MEM_FILES   = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_memchr.c ft_memcmp.c ft_calloc.c

# Numbers files
NUM_DIR     = numbers/
NUM_FILES   = ft_atoi.c ft_atof.c ft_itoa.c ft_utoa.c

# Output files
OUT_DIR     = output/
OUT_FILES   = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Printf files
PFX_DIR     = printf/
PFX_FILES   = ft_printf.c ft_handle_format.c ft_print_char.c \
              ft_print_str.c ft_print_ptr.c ft_print_int.c \
              ft_print_number.c ft_print_hex.c

# Lists files (Bonus)
LST_DIR     = lists/
LST_FILES   = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
              ft_lstmap.c

# Combining all sources with their respective prefixes
SRC_FILES   = $(addprefix $(CHAR_DIR), $(CHAR_FILES)) \
              $(addprefix $(STR_DIR), $(STR_FILES)) \
              $(addprefix $(MEM_DIR), $(MEM_FILES)) \
              $(addprefix $(NUM_DIR), $(NUM_FILES)) \
              $(addprefix $(OUT_DIR), $(OUT_FILES)) \
              $(addprefix $(PFX_DIR), $(PFX_FILES))

BONUS_FILES = $(addprefix $(LST_DIR), $(LST_FILES))

# Convert paths to objects
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))
DEPS        = $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

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

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✨ Libft compiled successfully!$(RESET)"

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)✨ Libft Bonus compiled successfully!$(RESET)"

# Create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile .c into .o inside obj/
$(OBJ_DIR)/%.o: %.c Makefile | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)🧹 Libft objects cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  Libft archive removed.$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re