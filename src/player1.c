/*
** player1.c for player1.c in /home/TAN_S/PSU_2016_navy/src/player/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Feb  2 19:28:41 2017 Sébastien TAN
** Last update Fri Feb 17 23:09:35 2017 Sébastien TAN
*/

#include <sys/stat.h>
#include "my.h"

int			player_1(char **map)
{
  struct sigaction	sig;

  sig.sa_flags = SA_SIGINFO;
  sig.sa_sigaction = catch_signal;
  if ((sigemptyset(&sig.sa_mask)) == -1)
    return (84);
  if ((sigaction(SIGUSR1, &sig, 0)) == - 1)
    return (84);
  my_putstr("my_pid: ");
  my_putnbr(getpid());
  my_putchar('\n');
  my_putstr("waiting for enemy connection...\n");
  pause();
  if ((kill(g_global, SIGUSR2)) == - 1)
    return (84);
  my_putstr("\nenemy connected\n\n");
  disp_map(map);
  my_putstr("attack: ");
  if (game_player1(map) == 84)
    return (84);
  return (0);
}

void			catch_signal(__attribute__((unused)) int sig, siginfo_t *info,
				     __attribute__((unused)) void *nothing)
{
  g_global = info->si_pid;
}

int			game_player1(char **map)
{
  int			win;
  int			lose;
  int			value;
  char			*shoot;

  win = 0;
  lose = 0;
  value = 0;
  while (win < 14 && lose < 14 && (shoot = get_next_line(0)))
    {
      if (check_coord(shoot) == 1)
	value = 1;
      else
	value = send_signal(map, shoot, &win, &lose);
      if (value == 84)
	return (84);
      else if (value == 1)
	my_putstr("wrong position\n");
      else
	disp_map(map);
      my_putstr("attack: ");
    }
  disp_win_lose(win, lose);
  return (0);
}
