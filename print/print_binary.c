/*
** print_binary.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 15 10:03:12 2016 Arthur Baurens
** Last update Tue Nov 15 20:27:14 2016 Arthur Baurens
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

int			print_binary(void *data, t_arg *modif)
{
  int			ret;
  int			padding;
  int			disp_len;
  unsigned int		*value;
  unsigned long int	to_print;

  ret = 0;
  value = (unsigned int *)data;
  get_sign(modif, *value, &to_print);
  disp_len = get_num_lenght(to_print, "01");
  ret += (padding = do_padding(modif, -1, disp_len, -1));
  ret += my_putunbr_base(to_print, "01");
  ret += do_padding(modif, padding, disp_len, -1);
  return (ret);
}
