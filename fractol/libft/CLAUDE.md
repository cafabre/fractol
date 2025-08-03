# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a 42 School libft project - a custom implementation of the C standard library functions. The project creates a static library (`libft.a`) containing reimplemented standard C functions plus additional utility functions.

## Build Commands

- **Build library**: `make` or `make all`
- **Build with bonus functions**: `make bonus`
- **Clean object files**: `make clean`
- **Full clean (objects + library)**: `make fclean`  
- **Rebuild from scratch**: `make re`

The library is built with strict compilation flags: `-Wall -Werror -Wextra`

## Code Architecture

### Core Structure
- **Main library functions**: Standard C library reimplementations (string, memory, character functions)
- **Additional functions**: Extended string manipulation and utility functions
- **Bonus functions**: Linked list manipulation functions using `t_list` structure

### Function Categories
1. **Character functions**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
2. **String functions**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
3. **Memory functions**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
4. **Additional functions**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
5. **File descriptor functions**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
6. **Bonus linked list functions**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Key Data Structure
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

## Development Notes

- All functions follow the `ft_` prefix convention
- The project uses 42 School's coding standard (header comments, specific formatting)
- Memory management is crucial - functions like `ft_split` include proper cleanup mechanisms
- The library includes both standard library equivalents and additional utility functions
- Use `#include "libft.h"` to access all function prototypes