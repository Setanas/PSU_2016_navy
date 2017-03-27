/*
** my_putstr.c for my_putstr.c in /home/TAN_S/PSU_2016_navy
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Mon Jan 30 17:45:03 2017 Sébastien TAN
** Last update Thu Feb  9 17:17:09 2017 Sébastien TAN
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	check_coord(char *str)
{
  char	spasfon;

  spasfon = 0;
  if (my_strlen(str) != 2)
    return (1);
  if (str[0] >= '0' && str[0] <= '8')
    {
      spasfon = str[0];
      str[0] = str[1];
      str[1] = spasfon;
    }
  if (str[0] >= 97 && str[0] <= 104)
    str[0] -= 32;
  if (str[0] >= 65 && str[0] <= 72)
    if (str[1] >= 49 && str[1] <= 56)
      return (0);
  return (1);
}
