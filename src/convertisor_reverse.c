/*
** convertisor_reverse.c for convertisor_reverse.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Feb  5 22:12:52 2017 Sébastien TAN
** Last update Wed Feb 15 19:01:01 2017 Sébastien TAN
*/

#include "my.h"

int	convert_into_letter(char *str)
{
  int	value;

  value = 0;
  if (str[0] == '1')
    value = value + 4;
  if (str[1] == '1')
    value = value + 2;
  if (str[2] == '1')
    value = value + 1;
  value = value + 65;
  free(str);
  return (value);
}

int	convert_into_nbr(char *str)
{
  int	value;

  value = 0;
  if (str[0] == '1')
    value = value + 4;
  if (str[1] == '1')
    value = value + 2;
  if (str[2] == '1')
    value = value + 1;
  free(str);
  return (value);
}
