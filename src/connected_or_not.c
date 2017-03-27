/*
** connected_or_not.c for navy in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Feb 12 12:52:53 2017 Sébastien TAN
** Last update Sun Feb 12 13:07:25 2017 Sébastien TAN
*/

#include "my.h"

int	connected_or_not(int pid)
{
  int	incre;

  incre = 0;
  while (g_global == pid && incre < 500)
    {
      if ((kill(pid, SIGUSR1)) == - 1)
	return (84);
      usleep(200);
      incre++;
    }
  if (incre == 500)
    return (84);
  return (0);
}
