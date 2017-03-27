/*
** makemap.c for navy in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Feb 16 15:53:57 2017 Sébastien TAN
** Last update Thu Feb 16 15:54:02 2017 Sébastien TAN
*/

#include "my.h"

char	**makemap(char **map)
{
  if ((map = malloc(sizeof(char*) * 23)) == 0)
    return (NULL);
  map[0] = "my positions:\n\0";
  map[1] = " |A B C D E F G H\n\0";
  map[2] = "-+---------------\n\0";
  map[3] = "1|. . . . . . . .\n\0";
  map[4] = "2|. . . . . . . .\n\0";
  map[5] = "3|. . . . . . . .\n\0";
  map[6] = "4|. . . . . . . .\n\0";
  map[7] = "5|. . . . . . . .\n\0";
  map[8] = "6|. . . . . . . .\n\0";
  map[9] = "7|. . . . . . . .\n\0";
  map[10] = "8|. . . . . . . .\n\0";
  map[11] = "\nenemy's positions:\n |A B C D E F G H\n\0";
  map[12] = "-+---------------\n\0";
  map[13] = "1|. . . . . . . .\n\0";
  map[14] = "2|. . . . . . . .\n\0";
  map[15] = "3|. . . . . . . .\n\0";
  map[16] = "4|. . . . . . . .\n\0";
  map[17] = "5|. . . . . . . .\n\0";
  map[18] = "6|. . . . . . . .\n\0";
  map[19] = "7|. . . . . . . .\n\0";
  map[20] = "8|. . . . . . . .\n\n\0";
  map[21] = NULL;
  return (map);
}

char	**dropyourship(char **map, char **coord)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (coord[i] != NULL)
    {
      if (coord[i][2] < coord[i][5])
	while (j != (coord[i][0] - 48))
	  {
	    map[coord[i][3] - 46][(coord[i][2] - 65) * 2 + 2] = coord[i][0];
	    coord[i][2] += 1;
	    j++;
	  }
      else
	while (j != (coord[i][0] - 48))
	  {
	    map[coord[i][3] - 46][(coord[i][2] - 65) * 2 + 2] = coord[i][0];
	    coord[i][3] += 1;
	    j++;
	  }
      j = 0;
      i++;
    }
  return (map);
}

char	**strstrcpy(char **newmap, char **oldmap)
{
  int	i;
  int	u;
  int	o;

  i = 0;
  u = 0;
  o = 0;
  i = my_arraylen(oldmap);
  if ((newmap = malloc(sizeof(char*) * (i + 1))) == 0)
    return (NULL);
  while (u != i)
    {
      if ((newmap[u] = malloc(sizeof(char) * (my_strlen(oldmap[u]) + 1))) == 0)
	return (NULL);
      while (o != my_strlen(oldmap[u]))
	{
	  newmap[u][o] = oldmap[u][o];
	  o++;
	}
	newmap[u][o] = '\0';
      o = 0;
      u++;
    }
  newmap[u] = NULL;
  return (newmap);
}

int	my_arraylen(char **lel)
{
  int	i;

  i = 0;
  while (lel[i] != NULL)
    i++;
  return (i);
}
