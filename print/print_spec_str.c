/*
** print_spec_str.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 15 11:42:11 2016 Arthur Baurens
** Last update Fri Nov 18 23:33:02 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

static int	spec_str_len(char *str, int len)
{
  int		i;
  int		final_size;

  i = 0;
  final_size = 0;
  len = (len <= 0 ? str_len(str) : len);
  while (i < len)
    {
      if (str[i] < 32 || str[i] >= 127)
	final_size += 4;
      final_size++;
      i++;
    }
  return (final_size);
}

int	my_put_specstr(char *str, int len)
{
  int	i;
  int	ret;
  int	disp_len;

  i = 0;
  ret = 0;
  len = (len <= 0 ? str_len(str) : len);
  while (i < len)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  ret += my_putstr("\\", 0);
	  disp_len = get_num_lenght((unsigned char)str[i], "01234567");
	  while (disp_len < 3)
	    {
	      disp_len++;
	      ret += my_putstr("0", 0);
	    }
	  ret += my_putunbr_base((unsigned char)str[i], "01234567");
	}
      else
	ret += my_putstr(&str[i], 1);
      i++;
    }
  return (ret);
}

int	print_true_string(void *data, t_arg *modif)
{
  int	ret;
  int	padding;
  int	disp_len;
  char	**value;

  ret = 0;
  value = (char **)data;
  if (*value == NULL)
    *value = "(null)";
  disp_len = spec_str_len(*value, 0);
  ret += (padding = do_padding(modif, -1, disp_len, -1));
  ret += my_put_specstr(*value, 0);
  ret += do_padding(modif, padding, disp_len, -1);
  return (ret);
}
