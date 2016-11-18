/*
** main.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 11:18:28 2016 Arthur Baurens
** Last update Fri Nov 18 23:31:18 2016 Arthur Baurens
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
  /*    */test1 = printf("R : avec %10s|\n", NULL);
  printf("\n");
  /* */test2 = my_printf("M : avec %10s|\n", NULL);
  my_printf("\n");
  /*printf("LEN = %d\n", test1);*/
  /*printf("LEN = %d\n", test2);*/
  return (0);
}
