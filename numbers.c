/*
** numbers.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 16:45:46 2016 Arthur Baurens
** Last update Tue Nov 15 20:14:42 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

int	get_num_lenght(unsigned long int nbr, const char *base)
{
  int	len;
  int	b_len;
  len = 0;

  if (nbr == 0)
    return (1);
  b_len = str_len(base);
  while (nbr > 0)
    {
      len++;
      nbr /= b_len;
    }
  return (len);
}

int	my_putnbr_base(long int nbr, const char *base)
{
  char	v;
  int	ret;
  int	b_len;

  ret = 0;
  b_len = str_len(base);
  if (nbr < 0)
    {
      ret++;
      write(1, "-", 1);
      nbr *= -1;
    }
  if (nbr / b_len > 0)
    ret += my_putnbr_base(nbr / b_len, base);
  v = base[nbr % b_len];
  ret++;
  write(1, &v, 1);
  return (ret);
}

int	my_putunbr_base(unsigned long int nbr, const char *base)
{
  char	v;
  int	ret;
  int	b_len;

  ret = 0;
  b_len = str_len(base);
  if (nbr / b_len > 0)
    ret += my_putnbr_base(nbr / b_len, base);
  v = base[nbr % b_len];
  write(1, &v, 1);
  ret++;
  return (ret);
}

int	get_nbr(char *str)
{
  int	sign;
  int	i;
  long	res;

  i = 0;
  sign = 1;
  res = 0;
  while (str && str[i] && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	sign *= -1;
      i++;
    }
  while (str && str[i] && str[i] >= '0' && str[i] <= '9')
    {
      res = res * 10 + (str[i] - '0');
      if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	return (0);
      i++;
    }
  return ((int)(res * sign));
}
