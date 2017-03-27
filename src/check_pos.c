/*
** check_pos.c for check_pos.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Mon Jan 30 22:08:42 2017 Sébastien TAN
** Last update Sat Feb 18 20:05:42 2017 Sébastien TAN
*/

#include "my.h"

int	check_pos(char *pos)
{
  swap_1(pos);
  swap_2(pos);
  if (pos[2] == pos[5] && pos[2] >= 65 && pos[2] <= 90)
    {
      if (check_nbr(pos) == 84)
        return (84);
      return (0);
    }
  else if (pos[3] == pos[6] && pos[3] >= 49 && pos[3] <= 56)
    {
      if (check_letter(pos) == 84)
        return (84);
      return (0);
    }
  else
    return (84);
  return (0);
}

void	swap_1(char *pos)
{
  char	stock;

  if (pos[2] < 65 && pos[2] > 90)
    {
      stock = pos[2];
      pos[2] = pos[3];
      pos[3] = stock;
    }
  if (pos[5] < 65 && pos[5] > 90)
    {
      stock = pos[5];
      pos[5] = pos[6];
      pos[6] = stock;
    }
}

void	swap_2(char *pos)
{
  char	stock_1;
  char	stock_2;

  if (pos[2] > pos[5] || pos[3] > pos[6])
    {
      stock_1 = pos[2];
      stock_2 = pos[3];
      pos[2] = pos[5];
      pos[3] = pos[6];
      pos[5] = stock_1;
      pos[6] = stock_2;
    }
}

int	check_nbr(char *pos)
{
  if (pos[6] == 57 || pos[6] == 48)
    return (84);
  if (pos[6] - pos[3] != pos[0] - 49)
    return (84);
  return (0);
}

int	check_letter(char *pos)
{
  if (pos[5] > 72 || pos[5] < 65)
    return (84);
  if (pos[5] - pos[2] != pos[0] - 49)
    return (84);
  return (0);
}
