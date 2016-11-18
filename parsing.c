/*
** parsing.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat Nov 12 17:05:05 2016 Arthur Baurens
** Last update Fri Nov 18 22:50:38 2016 Arthur Baurens
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

#include <unistd.h>

static int	print_arg(t_arg *arg, va_list *arguments)
{
  int		i;
  int		ret;
  int		(*print[FLAG_COUNT - 1])(void *, t_arg *modif);
  char		*cmp;
  long int	ptr;

  i = -1;
  ret = 0;
  cmp = FLAGS;
  print[0] = print_int;
  print[1] = print_int;
  print[2] = print_uint;
  print[3] = print_char;
  print[4] = print_octal;
  print[5] = print_hex;
  print[6] = print_hex_up;
  print[7] = print_string;
  print[8] = print_pointer;
  print[9] = print_binary;
  print[10] = print_true_string;
  while (cmp[++i] != arg->specifier && i < FLAG_COUNT - 1);
  if (i < FLAG_COUNT - 1)
    {
      ptr = va_arg(*arguments, long int);
      ret += print[i](&ptr, arg);
    }
  return (ret);
}

static int	display_argument_2(t_arg *arg, t_list **list)
{
  t_list	*tmp;

  tmp = NULL;
  if (arg->rest != NULL)
    {
      tmp = parse_format(arg->rest);
      while (tmp->next != NULL && (tmp = tmp->next)->next != NULL);
      rm_from_list(list, *list);
      while (tmp != NULL)
	{
	  push(list, tmp->token, str_len(tmp->token), tmp->type);
	  tmp = tmp->prev;
	}
      push(list, "lol", 3, 0);
    }
  return (0);
}

static int print_flags(const char *flags)
{
  int		i;

  if (is_in_str('#', flags))
    i += my_putstr("#", 0);
  if (is_in_str('+', flags))
    i += my_putstr("+", 0);
  else if (is_in_str(' ', flags))
    i += my_putstr(" ", 0);
  if (is_in_str('-', flags))
    i += my_putstr("-", 0);
  else if (is_in_str('0', flags))
    i += my_putstr("0", 0);
  return (i);
}

static int	display_argument(t_arg *arg, t_list **list)
{
  int		ret;
  char		*flags;

  ret = 1;
  my_putstr("%", 0);
  //printf("\nREST=%s\n", arg->rest);
  ret += print_flags(arg->flags);
  if (arg->width != 0)
    ret += my_putnbr_base(arg->width, "0123456789");
  if (arg->precision >= 0)
    {
      ret += my_putstr(".", 0);
      ret += my_putnbr_base(arg->precision, "0123456789");
    }
  return(ret + display_argument_2(arg, list));
}

int	parse_flag(char *token, va_list *arguments, t_list **list, int *ret)
{
  int	i;
  t_arg	arg;

  i = 0;
  if (token[i++] != '%')
    return (-1);
  i += get_flags(&token[i], &arg);
  i += get_width(&token[i], &arg, arguments);
  i += get_precision(&token[i], &arg, arguments);
  i += get_length(&token[i], &arg);
  if (get_specifier(&token[i], &arg) < 0)
    return (-1);
  if (token[i] == '%')
    {
      *ret += print_purcent(NULL, NULL);
      return (1);
    }
  if (arg.specifier == 0)
    {
      *ret += display_argument(&arg, list);
      return (0);
    }
  *ret += print_arg(&arg, arguments);
  free(arg.flags);
  return (1);
}
