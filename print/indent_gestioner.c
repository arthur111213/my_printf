/*
** indent_gestioner.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 14 13:32:57 2016 Arthur Baurens
** Last update Tue Nov 15 19:44:56 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static char ivs(t_arg *modif)
{
  if (modif->precision != 0 || modif->specifier == 's' || modif->specifier == 'S')
    return (0);
  return (1);
}

static int	do_padding_center(t_arg *modif, int *padding,
				  int disp_len, int use)
{
  int		ret;

  ret = 0;
  if (*padding == -1 && (*padding = is_in_str('-', modif->flags)) == 0)
    {
      while (modif->width > disp_len)
	{
	  ret++;
	  modif->width--;
	  write(1, is_in_str('0', modif->flags) && ivs(modif) ? "0" : " ", 1);
	}
    }
  else if (use == 1)
    {
      while (modif->width > disp_len)
	{
	  ret++;
	  modif->width--;
	  write(1, " ", 1);
	}
    }
  return (ret);
}

int	do_padding(t_arg *modif, int padding, int disp_len, char sign)
{
  int	ret;
  int	use;
  char	zeros;
  char	disp_sign;

  ret = 0;
  zeros = is_in_str('0', modif->flags) && ivs(modif);
  disp_sign = is_in_str('+', modif->flags);
  if ((use = padding) == -1 && sign != -1 && zeros && (disp_sign || sign == 1))
    {
      ret++;
      write(1, sign == 0 ? "+" : "-", 1);
    }
  ret += do_padding_center(modif, &padding, disp_len, use);
  if (sign != -1 && use == -1 && !zeros && (disp_sign || sign == 1))
    {
      ret++;
      write(1, sign == 0 ? "+" : "-", 1);
    }
  return (ret);
}
