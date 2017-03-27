/*
** send_signal_1_5.c for mein_über_gain_de_place in /home/devier_n/B2-Unix_System_Programmation/PSU_2016_navy/src
** 
** Made by Nicolas DEVIERS
** Login   <devier_n@epitech.net>
** 
** Started on  Thu Feb  9 20:09:45 2017 Nicolas DEVIERS
** Last update Tue Feb 14 18:53:48 2017 Sébastien TAN
*/

#include <signal.h>
#include "my.h"

int	free_them(char *shoot, char *x, char *y)
{
  free(shoot);
  free(x);
  free(y);
  return (84);
}

void	signal1(__attribute__((unused)) int sig, siginfo_t *info,
		__attribute__((unused)) void	*nothing)
{
  if (g_global == info->si_pid)
    g_global = 0;
}

void	signal2(__attribute__((unused)) int sig, siginfo_t *info,
		__attribute__((unused)) void *nothing)
{
  if (g_global == info->si_pid)
    g_global = 1;
}

