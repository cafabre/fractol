#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

/* ************************************************************************** */
/* 								  STRUCTURES                                  */
/* ************************************************************************** */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/* 									PRINTF                                    */
/* ************************************************************************** */
int		ft_printf(const char *format, ...);
int		ft_handle_format(const char format, va_list args);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_int(int nbr);
int		ft_print_unsigned(unsigned int nbr);
int		ft_print_hex(unsigned int nbr, char specifier);

/* ************************************************************************** */
/* 									 CHARS                                    */
/* ************************************************************************** */
int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_isascii(int c);
int		ft_isspace(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ************************************************************************** */
/* 									STRINGS                                   */
/* ************************************************************************** */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);

/* ************************************************************************** */
/* 									MEMORY                                    */
/* ************************************************************************** */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_calloc(size_t n, size_t s);

/* ************************************************************************** */
/* 									NUMBERS                                   */
/* ************************************************************************** */
int		ft_atoi(const char *str);
double	ft_atof(const char *nptr);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int nbr);

/* ************************************************************************** */
/* 									OUTPUT                                    */
/* ************************************************************************** */
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/* 									 LISTS                                    */
/* ************************************************************************** */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif