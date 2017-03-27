/*
** my_put_nbr.c for my_put_nbr.c in /home/TAN_S/CPool_workshoplib/lib/my
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Oct 21 15:07:28 2016 Sébastien TAN
** Last update Thu Feb  9 20:24:35 2017 Nicolas DEVIERS
*/

#include "my.h"

void	my_putnbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  my_putnbr(nb);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}
