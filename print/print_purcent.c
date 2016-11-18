/*
** print_purcent.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/print/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 15 15:20:48 2016 Arthur Baurens
** Last update Fri Nov 18 10:10:00 2016 Arthur Baurens
*/

#include <unistd.h>
#include "my_printf.h"

int	print_purcent(void *data, t_arg *modif)
{
  data = data;
  modif = modif;
  write(1, "%", 1);
  return (1);
}
