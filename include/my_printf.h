/*
** my_printf.h for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 11:17:16 2016 Arthur Baurens
** Last update Sat Dec  3 18:48:23 2016 Arthur Baurens
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_
# include <stdarg.h>

# define FLAGS "diucoxXspbS%"
# define FLAG_COUNT 12
# define STRING_TOKEN_TYPE 0;
# define FLAG_TOKEN_TYPE 1;

# define TRUE 1
# define FALSE 0
typedef char t_bool;

typedef struct		s_list
{
  char			*token;
  char			type;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_arg
{
  char			*flags;
  int			true_width;
  int			width;
  int			precision;
  char			length;
  char			specifier;
  char			*rest;
}			t_arg;

int	my_printf(const char *, ...);
t_list	*parse_format(char *form);

int	my_putstr(char *str, int n);

int	parse_flag(char *token, va_list *arguments, t_list **, int *ret);

int	get_flags(char *, t_arg *);
int	get_width(char *, t_arg *, va_list *lst);
int	get_precision(char *, t_arg *, va_list *lst);
int	get_length(char *, t_arg *);
int	get_specifier(char *, t_arg *);

int	print_int(void *data, t_arg *modif);
int	print_uint(void *data, t_arg *modif);
int	print_char(void *data, t_arg *modif);
int	print_octal(void *data, t_arg *modif);
int	print_hex(void *data, t_arg *modif);
int	print_hex_up(void *data, t_arg *modif);
int	print_string(void *data, t_arg *modif);
int	print_pointer(void *data, t_arg *modif);
int	print_binary(void *data, t_arg *modif);
int	print_true_string(void *data, t_arg *modif);
int	print_purcent(void *data, t_arg *modif);

int	push(t_list **list, char *token, int len, char type);
int	add_to_list(t_list **list, char *token, int len, char type);
t_list	*rm_list(t_list **list);
int	rm_from_list(t_list **list, t_list *elem);

void	display_list(t_list *);

int	str_len(const char *str);
char	is_in_str(char c, const char *str);
char	*my_strncat(const char *src1, const char *src2, int n);
int	my_put_specstr(char *str, int n);

int	get_num_lenght(unsigned long int nb, const char *base);
int	my_putnbr_base(long, const char *);
int	my_putunbr_base(unsigned long, const char *);
int	get_nbr(char *str);

int	do_padding(t_arg *modif, int padding, int disp_len, char sign);

#endif /* !MY_PRINTF_H_ */
