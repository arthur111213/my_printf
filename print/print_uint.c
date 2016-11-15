/*
** print_int.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 13:15:35 2016 Arthur Baurens
** Last update Tue Nov 15 14:08:59 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static char	get_sign(t_arg *args, long int value, unsigned long int *to_print)
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

int		print_uint(void *data, t_arg *modif)
{
  unsigned long int	to_print;
  unsigned long int	*value;
  int			padding;
  int			disp_len;

  value = (unsigned long int *)data;
  get_sign(modif, *value, &to_print);
  disp_len = get_num_lenght(to_print, "0123456789");
  modif->precision -= disp_len;
  disp_len += modif->precision;
  padding = do_padding(modif, -1, disp_len, -1);
  while (modif->precision-- > 0)
  write(1, "0", 1);
  my_putunbr_base(to_print, "0123456789");
  do_padding(modif, padding, disp_len, -1);
  return (0);
}
