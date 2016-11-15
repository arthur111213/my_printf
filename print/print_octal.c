/*
** pint_octal.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 19:17:23 2016 Arthur Baurens
** Last update Tue Nov 15 20:17:57 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static char	get_sign(t_arg *args, long int value, unsigned long int *to_print)
{
  unsigned int		int_buffer;
  unsigned short int	h_int_buffer;
  unsigned long int	final;

  int_buffer = value;
  h_int_buffer = value;
  if (args->length == 0)
    final = int_buffer;
  else if (args->length == 'h')
    final = h_int_buffer;
  else if (args->length == 'l')
    final = value;
  *to_print = final;
  return (1);
}

static void	calc_precision(t_arg *modif, int *disp_len)
{
    modif->precision -= *disp_len;
    if (modif->precision < 0)
      modif->precision = 0;
    *disp_len += modif->precision;
}

int			print_octal(void *data, t_arg *modif)
{
  int			ret;
  int			padding;
  int			disp_len;
  unsigned int		*value;
  unsigned long int	to_print;

  ret = 0;
  value = (unsigned int *)data;
  get_sign(modif, *value, &to_print);
  disp_len = get_num_lenght(to_print, "01234567");
  if (is_in_str('#', modif->flags) && to_print != 0)
    disp_len++;
  calc_precision(modif, &disp_len);
  ret += (padding = do_padding(modif, -1, disp_len, -1));
  if (is_in_str('#', modif->flags) && to_print != 0)
    ret += my_putstr("0", 0);
  while (modif->precision-- > 0)
    ret += my_putstr("0", 0);
  ret += my_putunbr_base(to_print, "01234567");
  ret += do_padding(modif, padding, disp_len, -1);
  return (ret);
}
