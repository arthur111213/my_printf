/*
** my_strings.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 11:28:38 2016 Arthur Baurens
** Last update Tue Nov 15 13:29:35 2016 Arthur Baurens
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"

int	str_len(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

char	is_in_str(char c, const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int	my_putstr(char *str, int n)
{
  int	len;

  len = str_len(str);
  if (n > 0)
    len = n;
  write(1, str, len);
  return (len);
}

char	*my_strncat(const char *src1, const char *src2, int n)
{
  int	i;
  int	j;
  int	ttlen;
  char	*tmp;

  ttlen = (n < 0 ? str_len(src1) + str_len(src2) : n);
  if (ttlen == 0)
    return (NULL);
  if ((tmp = malloc(sizeof(char) * (ttlen + 1))) == NULL)
    return(NULL);
  tmp[ttlen] = '\0';
  i = 0;
  while (src1 && src1[i] && (i < n || n < 0))
    {
      tmp[i] = src1[i];
      i++;
    }
  j = -1;
  while (src2 && src2[++j] && ((i + j) < n || n < 0))
    tmp[i + j] = src2[j];
  return (tmp);
}
