/*
** main.c for main.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Mon Jan 30 12:16:26 2017 Sébastien TAN
** Last update Wed Feb 15 19:55:26 2017 Sébastien TAN
*/

#include "my.h"

int	g_global = 0;

int	main(int ac, char **av)
{
  char	**pos;
  char	**map;

  map = NULL;
  pos = NULL;
  if (ac == 2)
    {
      if (caseplaya1(av, pos, map) != 0)
	return (84);
    }
  else if (ac == 3)
    {
      if (caseplaya2(av, pos, map) != 0)
	return (84);
    }
  else
    return (84);
  return (0);
}

int	caseplaya2(char **av, char **pos, char **map)
{
  int	incre;

  incre = 0;
  if ((pos = error(av[2])) == NULL)
    return (84);
  if ((map = dropyourship(strstrcpy(map, makemap(map)), pos)) == 0)
    return (84);
  if ((player_2(map, my_getnbr(av[1]))) == 84)
    {
      while (map[incre] != NULL)
	{
	  free(map[incre]);
	  incre++;
	}
      return (84);
    }
  fly_you_fool(pos, map);
  return (0);
}

int	caseplaya1(char **av, char **pos, char **map)
{
  int	incre;

  incre = 0;
  if (av[1][0] == '-' && av[1][1] == 'h')
    return (help());
  if ((pos = error(av[1])) == NULL)
    return (84);
  if ((map = dropyourship(strstrcpy(map, makemap(map)), pos)) == 0)
    return (84);
  if ((player_1(map)) == 84)
    {
      while (map[incre] != NULL)
	{
	  free(map[incre]);
	  incre++;
	}
      return (84);
    }
  fly_you_fool(pos, map);
  return (0);
}

int	fly_you_fool(char **arr1, char **arr2)
{
  int	i;

  i = 0;
  if (arr1 != NULL)
    {
      while (arr1[i] != 0)
  	{
  	  free(arr1[i]);
  	  i++;
  	}
      free(arr1);
      arr1 = NULL;
      fly_you_fool(arr2, arr1);
    }
  return (0);
}
