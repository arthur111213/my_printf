/*
** main.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 11:18:28 2016 Arthur Baurens
** Last update Tue Nov 15 20:36:32 2016 Arthur Baurens
*/

#include <stdio.h>

#include "my_printf.h"


int	main(int ac, char **av)
{
  int	lol;
  int	test1;
  int	test2;
  unsigned char	lol2[] = "TEST";

  lol = 10;
  /*    */test1 = printf("[REAL] : CECI EST UN TEST|On test les char : %#+040.15d_LOL%   %%%\n", lol);
  printf("LEN = %d\n", test1);
  /* */test2 = my_printf("[ MY ] : CECI EST UN TEST|On test les char : %#+040.15d_LOL%   %%%\n", lol);
  printf("LEN = %d\n", test2);
  return (0);
}
