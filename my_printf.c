/*
** my_printf.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 10:51:57 2016 Arthur Baurens
** Last update Fri Nov 18 23:26:36 2016 Arthur Baurens
*/

#include <stdio.h>

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

int	get_string_part(char *f, t_list **res, int i, int *count)
{
  int	j;

  j = 0;
  while (f[i + j] && (f[i + j] != '%'))
    j++;
  add_to_list(res, &f[i], j, 0);
  return (j);
}

t_list		*parse_format(char *f)
{
  int		i;
  int		j;
  int		count;
  t_list	*res;
  char		*fl;

  i = 0;
  res = NULL;
  fl = FLAGS;
  count = 0;
  while (f[i])
    {
      j = 0;
      i += get_string_part(f, &res, i, &count);
      while (f[i + j] && f[i + j + 1] && (!is_in_str(f[i + j], fl) || j == 0))
	j++;
      add_to_list(&res, &f[i], j + 1, 1);
      count++;
      i += j;
      if (f[i] == '\0')
	return (res);
      i++;
    }
  return (res);
}

int		my_printf(const char *format, ...)
{
  va_list	args;
  t_list	*disp;
  int		ret;
  char		*form;

  ret = str_len(format);
  form = my_strncat(format, NULL, ret - (format[ret - 1] == '%'));
  ret = 0;
  va_start(args, format);
  disp = parse_format(is_in_str('%', form) ? (char *)format : form);
  while (disp != NULL)
    {
      if (disp->type == 0)
	ret += my_putstr(disp->token, 0);
      else if (parse_flag(disp->token, &args, &disp, &ret) < 0)
	{
	  rm_list(&disp);
	  return (ret);
	}
      rm_from_list(&disp, disp);
    }
  free(form);
  va_end(args);
  return (ret);
}
