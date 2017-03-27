/*
** disp_map.c for disp_map.c in /home/TAN_S/PSU_2016_navy/src/player
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Feb  2 20:22:57 2017 Sébastien TAN
** Last update Thu Feb  9 20:20:22 2017 Nicolas DEVIERS
*/

#include "my.h"

void	disp_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      i++;
    }
}

void	disp_win_lose(int win, int lose)
{
  if (win == 14)
    my_putstr("I won\n");
  else if (lose == 14)
    my_putstr("Enemy won\n");
}
