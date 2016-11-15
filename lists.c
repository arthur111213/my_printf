/*
** lists.c for printf in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_my_printf/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Nov  9 11:31:12 2016 Arthur Baurens
** Last update Tue Nov 15 19:07:35 2016 Arthur Baurens
*/

#include <stdlib.h>
#include "my_printf.h"

int		push(t_list **list, char *token, int len, char type)
{
  int		i;
  t_list	*elem;

  i = -1;
  if (len <= 0)
    return (1);
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return(0);
  if ((elem->token = malloc(sizeof(char) * (len + 1))) == NULL)
    return(0);
  elem->type = type;
  elem->token[len] = '\0';
  while (++i < len)
    elem->token[i] = token[i];
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (1);
}

int		add_to_list(t_list **list, char *token, int len, char type)
{
  int		i;
  t_list	*last;
  t_list	*elem;

  i = -1;
  last = *list;
  if (len <= 0)
    return (1);
  while (last != NULL && last->next != NULL)
    last = last->next;
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return(0);
  if ((elem->token = malloc(sizeof(char) * (len + 1))) == NULL)
    return(0);
  elem->type = type;
  elem->token[len] = '\0';
  while (++i < len)
    elem->token[i] = token[i];
  elem->next = NULL;
  elem->prev = last;
  if (last != NULL)
    last->next = elem;
  else
    *list = elem;
  return (1);
}

t_list		*rm_list(t_list **list)
{
  t_list	*tmp;

  while (*list != NULL)
    {
      tmp = *list;
      *list = tmp->next;
      free(tmp->token);
      free(tmp);
    }
  return (NULL);
}

int	rm_from_list(t_list **list, t_list *elem)
{
  if (*list == NULL)
    return (0);
  if (*list == elem)
    *list = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  free(elem->token);
  free(elem);
  return (0);
}
