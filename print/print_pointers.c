/*
** print_pointers.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 15 10:23:10 2016 Arthur Baurens
** Last update Tue Nov 15 20:30:25 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static int	start_display(t_arg *modif)
{
  int		ret;

  ret = 0;
  if (!is_in_str('0', modif->flags) || modif->precision != 0)
    {
      if (is_in_str('+', modif->flags))
	ret += my_putstr("+", 0);
      ret += my_putstr("0x", 0);
    }
  while (modif->precision-- > 0)
    ret += my_putstr("0", 0);
  return (ret);
}

int			print_pointer(void *data, t_arg *modif)
{
  int			ret;
  int			padding;
  int			disp_len;
  unsigned long int	*value;

  ret = 0;
  value = (unsigned long int *)data;
  disp_len = get_num_lenght(*value, "0123456789abcdef");
  modif->precision -= disp_len;
  disp_len += modif->precision;
  disp_len += 2;
  if (is_in_str('0', modif->flags) && modif->precision == 0)
    {
      if (is_in_str('+', modif->flags))
	ret += my_putstr("+", 0);
      ret += my_putstr("0x", 0);
    }
  if (is_in_str('+', modif->flags))
    disp_len++;
  ret += (padding = do_padding(modif, -1, disp_len, -1));
  ret += start_display(modif);
  ret += my_putunbr_base(*value, "0123456789abcdef");
  ret += do_padding(modif, padding, disp_len, -1);
  return (ret);
}
