/*
** help.c for mein_über_ayuda in /home/devier_n/B2-Unix_System_Programmation/PSU_2016_navy/src
** 
** Made by Nicolas DEVIERS
** Login   <devier_n@epitech.net>
** 
** Started on  Wed Feb  1 10:58:21 2017 Nicolas DEVIERS
** Last update Thu Feb 16 14:57:14 2017 Nicolas DEVIERS
*/

#include	"my.h"

int	help()
{
  my_putstr("USAGE\n\t\t./navy [first_player_pid] navy_positions\n");
  my_putstr("\nDESCRIPTION\n\t\tfirst_player_pid\tonly for the 2nd player.");
  my_putstr("  pid of the first player.\n\t\tnavy_positions\t\tfile ");
  my_putstr("representing the positions of the ships.\n");
  return (0);
}
