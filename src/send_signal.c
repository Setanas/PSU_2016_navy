/*
** send_signal.c for send_signal.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sat Feb  4 13:21:35 2017 Sébastien TAN
** Last update Thu Feb  9 20:34:21 2017 Nicolas DEVIERS
*/

#include <signal.h>
#include "my.h"

int	send_signal(char **map, char *shoot, int *win, int *lose)
{
  char  *x;
  char  *y;

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
  if ((touched_or_not(map, shoot, win, lose)) == 84)
    return (free_them(shoot, x, y));
  free_them(shoot, x, y);
  return (0);
}

int	send_sig(char *pos)
{
  int	incre;

  incre = 0;
  while (pos[incre] != 0)
    {
      if (pos[incre] == '0')
        {
          if ((kill(g_global, SIGUSR1)) == - 1)
            return (84);
        }
      else
        if ((kill(g_global, SIGUSR2)) == - 1)
          return (84);
      incre++;
      usleep(5000);
    }
  return (0);
}

int	touched_or_not(char **map, char *shoot, int *win, int *lose)
{
  int	pid;

  pid = g_global;
  if (init_sig() == 84)
    return (84);
  map_after(map, shoot, win);
  g_global = pid;
  if (*win != 14)
    {
      my_putstr("waiting for ennemy's attack...\n");
      if ((receive_signal(map, lose)) == 84)
        return (84);
      g_global = pid;
    }
  return (0);
}

int	init_sig()
{
  struct sigaction	touch;
  struct sigaction	miss;

  touch.sa_flags = SA_SIGINFO;
  miss.sa_flags = SA_SIGINFO;
  touch.sa_sigaction = touched_sig;
  miss.sa_sigaction = missed_sig;
  if ((sigemptyset(&touch.sa_mask)) == 84)
    return (84);
  if ((sigemptyset(&miss.sa_mask)) == 84)
    return (84);
  if ((sigaction(SIGUSR1, &touch, 0)) == - 1)
    return (84);
  if ((sigaction(SIGUSR2, &miss, 0)) == - 1)
    return (84);
  return (0);
}
