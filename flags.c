/*
** flags.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Nov 10 17:22:31 2016 Arthur Baurens
** Last update Tue Nov 15 15:44:16 2016 Arthur Baurens
*/

#include <stdlib.h>
#include "my_printf.h"

int	get_flags(char *token, t_arg *args)
{
  int	i;
  char	*cmp;

  i = 0;
  cmp = "-+ #";
  while (token[i] && is_in_str(token[i], cmp))
    i++;
  if (token[i] && token[i] == '0')
    i++;
  args->flags = my_strncat(NULL, token, i);
  return (i);
}

int	get_width(char *token, t_arg *args, va_list *lst)
{
  int	i;
  char	*cmp;
  char	*tmp;

  i = -1;
  cmp = "0123456789";
  if (token[i] && token[++i] == '*')
    {
      args->width = va_arg(*lst, int);
      args->true_width = args->width;
      if (args->width < 0)
	{
	  args->width *= -1;
	  tmp = args->flags;
	  args->flags = my_strncat("-", args->flags, str_len(args->flags) + 1);
	  free(tmp);
	}
      return (1);
    }
  while (token[i] && is_in_str(token[i++], cmp));
  cmp = my_strncat(NULL, token, i - 1);
  args->width = get_nbr(cmp);
  args->true_width = args->width;
  free(cmp);
  return (i - 1);
}

int	get_precision(char *token, t_arg *args, va_list *lst)
{
  int	i;
  char	*cmp;

  i = 0;
  cmp = "0123456789";
  if (token[i++] != '.')
    {
      args->precision = -1;
      return (0);
    }
  if (token[i] == '*')
    {
      args->precision = va_arg(*lst, int);
      i++;
    }
  else
    {
      while (token[i] && is_in_str(token[i], cmp))
	i++;
      cmp = my_strncat(NULL, token, i);
      args->precision = get_nbr(&cmp[1]);
      free(cmp);
    }
  return (i);
}

int	get_length(char *token, t_arg *args)
{
  int	i;
  char	*cmp;

  i = 0;
  cmp = "hl";
  args->length = 0;
  if (token[i] && is_in_str(token[i], cmp))
    args->length = token[i++];
  return (i);
}

int	get_specifier(char *token, t_arg *args)
{
  int	i;
  char	*cmp;

  i = 0;
  cmp = FLAGS;
  args->specifier = 0;
  args->rest = token;
  if (token[i] && is_in_str(token[i], cmp))
    args->specifier = token[i++];
  if (args->length != 0 && args->specifier == 's')
    return (-1);
  return (i);
}
