/*
** print_hex_up.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 20:25:49 2016 Arthur Baurens
** Last update Tue Nov 15 20:26:11 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static char	get_sign(t_arg *args, long int value, unsigned long int *to_pr)
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
  *to_pr = final;
  return (1);
}

static void	calc_precision(t_arg *modif, int *disp_len)
{
    modif->precision -= *disp_len;
    if (modif->precision < 0)
      modif->precision = 0;
    *disp_len += modif->precision;
}

int			print_hex_up(void *data, t_arg *modif)
{
  int			padding[2];
  int			disp_len;
  unsigned int		*value;
  unsigned long int	to_print;

  padding[1] = 0;
  value = (unsigned int *)data;
  get_sign(modif, *value, &to_print);
  disp_len = get_num_lenght(to_print, "0123456789ABCDEF");
  calc_precision(modif, &disp_len);
  if (is_in_str('#', modif->flags) && to_print != 0)
    {
      if (is_in_str('0', modif->flags) && modif->precision == 0)
	padding[1] += my_putstr("0X", 0);
      disp_len += 2;
    }
  padding[0] = do_padding(modif, -1, disp_len, -1);
  if ((is_in_str('#', modif->flags) && to_print != 0 &&
       !is_in_str('0', modif->flags)) || modif->precision != 0)
    padding[1] += my_putstr("0X", 0);
  while (modif->precision-- > 0)
    padding[1] += my_putstr("0", 0);
  padding[1] += my_putnbr_base(to_print, "0123456789ABCDEF");
  padding[1] += do_padding(modif, padding[0], disp_len, -1);
  return (padding[1]);
}
