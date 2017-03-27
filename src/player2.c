/*
** player2.c for player2.c in /home/TAN_S/PSU_2016_navy/src/player/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Feb  2 20:43:02 2017 Sébastien TAN
** Last update Tue Feb 14 20:57:31 2017 Sébastien TAN
*/

#include <sys/stat.h>
#include "my.h"

int			player_2(char **map, int pid)
{
  struct sigaction	sig;

  sig.sa_flags = SA_SIGINFO;
  sig.sa_sigaction = catch_signal2;
  sigemptyset(&sig.sa_mask);
  my_putstr("my_pid: ");
  my_putnbr(getpid());
  my_putchar('\n');
  if ((sigaction(SIGUSR2, &sig, 0)) == - 1)
    return (84);
  g_global = pid;
  if ((connected_or_not(pid)) == 84)
    {
      my_putstr("unsuccessfully connected\nBad PID\n");
      return (84);
    }
  disp_map(map);
  g_global = pid;
  my_putstr("waiting for enemy's attack\n");
  if (game_player2(map, pid) == 84)
    return (84);
  return (0);
}

void			catch_signal2(__attribute__((unused)) int sig, siginfo_t *info,
				      __attribute__((unused)) void *nothing)
{
  if (g_global == info->si_pid)
    {
      my_putstr("successfully connected\n\n");
      g_global = 0;
    }
}

int			game_player2(char **map, int pid)
{
  int			win;
  int			lose;
  int			value;
  char			*shoot;

  value = 1;
  win = 0;
  lose = 0;
  if ((receive_signal(map, &lose)) == 84)
    return (84);
  usleep(5000);
  my_putstr("attack: ");
  while (lose < 14 && win < 14 && (shoot = get_next_line(0)))
    {
      value = send_signal_2(map, shoot, &win);
      if (value == 84)
	return (84);
      else if (value == 1)
	my_putstr("wrong position\nattack: ");
      else
	if ((waiting(map, win, &lose, pid)) == 84)
	  return (84);
    }
  disp_win_lose(win, lose);
  return (0);
}

int			waiting(char **map, int win, int *lose, int pid)
{
  usleep(50000);
  disp_map(map);
  if (win != 14 && *lose != 14)
    my_putstr("waiting for enemy's attack\n");
  g_global = pid;
  if (*lose != 14 && win != 14)
    {
      if ((receive_signal(map, lose)) == 84)
	return (84);
      if (*lose != 14)
	my_putstr("attack: ");
      if (*lose == 14 || win == 14)
	disp_map(map);
    }
  return (0);
}
int			touched_player2(char **map, char *shoot,
                                         int *win)
{
  struct sigaction      touch;
  struct sigaction      miss;

  touch.sa_flags = SA_SIGINFO;
  miss.sa_flags = SA_SIGINFO;
  touch.sa_sigaction = touched_sig;
  miss.sa_sigaction = missed_sig;
  sigemptyset(&touch.sa_mask);
  sigemptyset(&miss.sa_mask);
  if ((sigaction(SIGUSR1, &touch, 0)) == - 1)
    return (84);
  if ((sigaction(SIGUSR2, &miss, 0)) == - 1)
    return (84);
  if ((map_after(map, shoot, win)) == 84)
    return (84);
  return (0);
}
