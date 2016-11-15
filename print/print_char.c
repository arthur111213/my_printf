/*
** print_char.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 19:03:04 2016 Arthur Baurens
** Last update Tue Nov 15 19:37:04 2016 Arthur Baurens
*/

#include "my_printf.h"
#include <unistd.h>

int	print_char(void *data, t_arg *modif)
{
  int	ret;
  char	*value;

  value = (char *)data;
  if (!is_in_str('-', modif->flags))
    {
      while (modif->width > 1)
	{
	  ret++;
	  modif->width--;
	  write(1, " ", 1);
	}
    }
  ret++;
  write(1, value, 1);
  if (is_in_str('-', modif->flags))
    {
      while (modif->width > 1)
	{
	  ret++;
	  modif->width--;
	  write(1, " ", 1);
	}
    }
  return (ret);
}
