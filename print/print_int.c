/*
** print_int.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 13:15:35 2016 Arthur Baurens
** Last update Tue Nov 15 20:18:59 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

char	get_sign(t_arg *args, long int value, unsigned long int *to_print)
{
  int		int_buffer;
  short int	h_int_buffer;
  long int	final;

  int_buffer = value;
  h_int_buffer = value;
  if (args->length == 0)
    final = int_buffer;
  else if (args->length == 'h')
    final = h_int_buffer;
  else if (args->length == 'l')
    final = value;
  if (final < 0)
    *to_print = -final;
  else
    *to_print = final;
  return (final < 0);
}

static int	precalc_padding(t_arg *modif, unsigned long int value, char s)
{
  int		ret;

  ret = get_num_lenght(value, "0123456789");
  modif->precision -= ret;
  if (modif->precision < 0)
    modif->precision = 0;
  ret += modif->precision;
  if (is_in_str('+', modif->flags) || s == 1)
    ret++;
  return (ret);
}

int			print_int(void *data, t_arg *modif)
{
  unsigned long int	to_print;
  long int		*value;
  char			sign;
  int			ret;
  int			padding;
  int			disp_len;

  ret = 0;
  value = (long int *)data;
  sign = get_sign(modif, *value, &to_print);
  disp_len = precalc_padding(modif, to_print, sign);
  ret += (padding = do_padding(modif, -1, disp_len, sign));
  while (modif->precision-- > 0)
    ret += my_putstr("0", 0);
  ret += my_putunbr_base(to_print, "0123456789");
  ret += do_padding(modif, padding, disp_len, sign);
  return (ret);
}
