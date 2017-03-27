/*
** wait_player2.c for wait_player2.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sat Feb  4 20:38:32 2017 Sébastien TAN
** Last update Thu Feb  9 20:37:44 2017 Nicolas DEVIERS
*/

#include <signal.h>
#include "my.h"

int	check_his_shot(char **map, int *lose, int ix, int iy)
{
  if (map[iy + 3][(ix - 65) * 2 + 2] == '.' ||

      map[iy + 3][(ix - 65) * 2 + 2] == 'x' ||
      map[iy + 3][(ix - 65) * 2 + 2] == 'o')
    {
      if (map[iy + 3][(ix - 65) * 2 + 2] != 'x')
	map[iy + 3][(ix - 65) * 2 + 2] = 'o';
      if ((kill (g_global, SIGUSR1)) == 84)
        return (84);
      my_putstr("missed\n\n");
    }
  else
    {
      *lose = *lose + 1;
      map[iy + 3][(ix - 65) * 2 + 2] = 'x';
      if ((kill (g_global, SIGUSR2)) == 84)
        return (84);
      my_putstr("hit\n\n");
    }
  return (0);
}

char			*catch(int pid)
{
  char			*pos;
  struct sigaction	usr1;
  struct sigaction	usr2;

  usr1.sa_flags = SA_SIGINFO;
  usr2.sa_flags = SA_SIGINFO;
  usr1.sa_sigaction = touched_sig;
  usr2.sa_sigaction = missed_sig;
  sigemptyset(&usr1.sa_mask);
  sigemptyset(&usr2.sa_mask);
  pos = NULL;
  if ((sigaction(SIGUSR1, &usr1, 0)) == - 1)
    return (NULL);
  if ((sigaction(SIGUSR2, &usr2, 0)) == - 1)
    return (NULL);
  if ((pos = put_in_pos(pid)) == NULL)
    return (NULL);
  return (pos);
}
