/*
** touched_and_wait.c for touched_and_wait.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sat Feb  4 14:04:24 2017 Sébastien TAN
** Last update Tue Feb 14 18:59:12 2017 Sébastien TAN
*/

#include <signal.h>
#include "my.h"

void	touched_sig(__attribute__((unused)) int sig,
		    siginfo_t *info, __attribute__((unused)) void *nothing)
{
  if (g_global == info->si_pid)
    g_global = 0;
}

void	missed_sig(__attribute__((unused)) int sig,
		   siginfo_t *info, __attribute__((unused)) void *nothing)
{
  if (g_global == info->si_pid)
    g_global = 1;
}

int	map_after(char **map, char *shoot, int *win)
{
  pause();
  if (g_global == 1)
    {
      *win = *win + 1;
      my_putstr("hit\n\n");
      map[shoot[1] - 36][(shoot[0] - 65) * 2 + 2] = 'x';
    }
  else
    {
      my_putstr("missed\n\n");
      if (map[shoot[1] - 36][(shoot[0] - 65) * 2 + 2] != 'x')
	map[shoot[1] - 36][(shoot[0] - 65) * 2 + 2] = 'o';
    }
  return (0);
}
