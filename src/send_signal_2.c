/*
** send_signal_2.c for navy in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Wed Feb  8 20:20:25 2017 Sébastien TAN
** Last update Thu Feb  9 20:30:05 2017 Nicolas DEVIERS
*/

#include <signal.h>
#include "my.h"

int	send_signal_2(char **map, char *shoot, int *win)
{
  char  *x;
  char  *y;

  if ((check_coord(shoot)) == 1)
    return (1);
  if ((x = my_getnbr_base(shoot[0] - 65, "01")) == NULL)
    return (84);
  if ((y = my_getnbr_base(shoot[1] - 49, "01")) == NULL)
    {
      free(x);
      return (84);
    }
  if ((send_sig(x)) == 84)
    return (free_them(shoot, x, y));
  if ((send_sig(y)) == 84)
    return (free_them(shoot, x, y));
  my_putstr(shoot);
  my_putstr(": ");
  if ((touched_or_not_2(map, shoot, win)) == 84)
    return (free_them(shoot, x, y));
  free_them(shoot, x, y);
  return (0);
}

int	touched_or_not_2(char **map, char *shoot, int *win)
{
  int   pid;

  pid = g_global;
  if (init_sig() == 84)
    return (84);
  map_after(map, shoot, win);
  g_global = pid;
  return (0);
}
