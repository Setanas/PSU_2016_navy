/*
** error.c for error.c in /home/TAN_S/PSU_2016_navy/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Mon Jan 30 22:27:35 2017 Sébastien TAN
** Last update Tue Feb 14 22:58:16 2017 Sébastien TAN
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

char	**error(char *file)
{
  char	**pos;
  int	i;
  int	fd;

  i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_puterror("No map or bad map"));
  if ((pos = malloc(sizeof(char *) * 6)) == NULL)
    return (my_puterror("Bad_malloc"));
  while ((pos[i] = get_next_line(fd)) && i != 6)
    i++;
  pos[i] = NULL;
  pos = capital(pos);
  if (error_next(pos, i) == 84)
    return (NULL);
  return (pos);
}

int	error_next(char **pos, int i)
{
  int   incre;
  int   line;

  incre = 0;
  line = 50;
  if (i != 4)
    return (put_error_free(pos, "Bad number of ships"));
  while (line != 54)
    {
      while (pos[incre][0] != line && incre != 4)
        {
          incre++;
          if (incre == 4)
	    return (put_error_free(pos, "Bad position of ships"));
        }
      if ((check_pos(pos[incre])) == 84)
        return (put_error_free(pos, "Bad position of ships"));
      line++;
      incre = 0;
    }
  return (0);
}

int	put_error_free(char **pos, char *str)
{
  int   incre;

  incre = 0;
  while (pos[incre] != NULL)
    {
      free(pos[incre]);
      incre++;
    }
  my_puterror(str);
  return (84);
}

char	**my_puterror(char *str)
{
  int   i;

  i = my_strlen(str);
  write(2, str, i);
  write(2, "\n", 1);
  return (NULL);
}

char	**capital(char **pos)
{
  int	i;
  int	u;

  i = 0;
  u = 0;
  while (pos[i] != 0)
    {
      while (pos[i][u] != '\0')
	{
	  if (pos[i][u] <= 122 && pos[i][u] >= 97)
	    pos[i][u] -= 32;
	  u++;
	}
      i++;
      u = 0;
    }
  return (pos);
}
