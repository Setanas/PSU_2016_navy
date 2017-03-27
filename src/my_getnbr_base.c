/*
** my_getnbr_base.c for my_getnbr_base.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Sun Feb  5 22:15:24 2017 Sébastien TAN
** Last update Thu Feb  9 17:18:36 2017 Sébastien TAN
*/

#include "my.h"

char	*my_getnbr_base(int nb, char *base)
{

  short int	pow;
  int	n1;
  char	*nber;
  int	i;

  if ((nber = malloc(sizeof(char) * 4)) == 0)
    return (NULL);
  pow = 4;
  i = 0;
  while (i != 3)
    nber[i++] = '0';
  i = 0;
  while (pow > 0)
    {
      n1 = nb / pow;
      nb = nb - n1 * pow;
      nber[i++] = base[n1];
      pow = pow / my_strlen(base);
    }
  nber[3] = '\0';
  return (nber);
}
