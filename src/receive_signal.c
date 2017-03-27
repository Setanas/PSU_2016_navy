/*
** receive_signal.c for receiver_signal.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Wed Feb  8 02:11:30 2017 Sébastien TAN
** Last update Thu Feb 16 15:31:07 2017 Sébastien TAN
*/

#include <signal.h>
#include <sys/stat.h>
#include "my.h"

int	receive_signal(char **map , int *lose)
{
  if ((init_sig()) == 84)
    return (84);
  if ((receive_signal_2(map, lose)) == 84)
    return (84);
  return (0);
}

int	receive_signal_2(char **map , int *lose)
{
  char  *x;
  char  *y;
  int   ix;
  int   iy;

  if ((x = put_in_pos()) == NULL)
    return (84);
  if ((y = put_in_pos()) == NULL)
    {
      free (x);
      return (84);
    }
  ix = convert_into_letter(x);
  iy = convert_into_nbr(y);
  my_putchar(ix);
  my_putchar(iy + 49);
  my_putstr(": ");
  usleep(50000);
  if ((check_his_shot(map, lose, ix, iy)) == 84)
    return (84);
  return (0);
}

char	*put_in_pos()
{
  int   incre;
  char  *pos;
  int   pid;

  pid = g_global;
  if ((pos = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  incre = 0;
  while (incre < 3)
    {
      pause();
      pos[incre] = g_global + 48;
      g_global = pid;
      incre++;
    }
  pos[3] = '\0';
  return (pos);
}
