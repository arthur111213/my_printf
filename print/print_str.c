/*
** print_str.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 15 11:23:34 2016 Arthur Baurens
** Last update Fri Nov 18 23:32:43 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

int	print_string(void *data, t_arg *modif)
{
  int	ret;
  int	disp_len;
  int	padding;
  char	**value;

  ret = 0;
  value = (char **)data;
  if (*value == NULL)
    *value = "(null)";
  disp_len = modif->precision <= 0 ? str_len(*value) : modif->precision;
  ret += (padding = do_padding(modif, -1, disp_len, -1));
  ret += my_putstr(*value, modif->precision);
  ret += do_padding(modif, padding, disp_len, -1);
  return (ret);
}
