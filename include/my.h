/*
** my.h for navy in /home/TAN_S/PSU_2016_navy/include
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Thu Feb  9 16:41:01 2017 Sébastien TAN
** Last update Wed Feb 15 19:54:18 2017 Sébastien TAN
*/

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* !READ_SIZE */

#ifndef MY_H_
# define MY_H_
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* check_pos.c */
int     check_pos(char *pos);
void    swap_1(char *pos);
void    swap_2(char *pos);
int     check_nbr(char *pos);
int     check_letter(char *pos);

/* convertisor_reveser.c */
int     convert_into_letter(char *str);
int     convert_into_nbr(char *str);

/* disp_map.c */
void    disp_map(char **map);
void    disp_win_lose(int win, int lose);

/* error.c */
char    **error(char *file);
int     error_next(char **pos, int i);
int     put_error_free(char **pos, char *str);
char    **my_puterror(char *str);
char    **capital(char **pos);

/* get_next_line.c */
typedef struct          s_static
{
  char          buffer[READ_SIZE];
  int           i;
  int           size;
}                       t_static;
char                    colgate_2_en_1(t_static *st, int *a, int what_to_do);
char                    *gain_some_line(char *retour);
int                     first_read(char *buffer, char **retour,
				   int *i, int fd);
char                    *reallocation(char *retour, t_static *st,
				      int a, int fd);
char                    *get_next_line(const int fd);

/* glob */
extern int g_global;

/* main.c */
int     caseplaya1(char **av, char **pos, char **map);

int     caseplaya2(char **av, char **pos, char **map);
int     fly_you_fool(char **arr1, char **arr2);

/* makemap.c */
char    **makemap(char **map);
char    **dropyourship(char **map, char **coord);
char    **strstrcpy(char **newmap, char **oldmap);
int     my_arraylen(char **lel);

/* my_getnbr_base.c */
char    *my_getnbr_base(int nbr, char *base);

/* my_getnbr.c */
int                     my_getnbr(char *str);
int                     un(int l, char *str, char *nb);
int                     deux(int j, int l, char *str, char *nb);
int                     trois(int o, char *nb);

/* my_put.h */
void                    my_putchar(char c);
void                    my_putnbr(int nb);
void                    my_putstr(char *str);
int                     my_strlen(char *str);
int                     check_coord(char *str);
int                     help();

/* player1.c */
int     player_1(char **map);
void    catch_signal(int sig, siginfo_t *info, void *nothing);
int     game_player1(char **map);
int     gameplay1(char **map, char *shoot, int *win, int *lose);
int     free_them(char *shoot, char *x, char *y);

/* player2.c */
int     player_2(char **map, int pid);
void    catch_signal2(int sig, siginfo_t *info, void *nothing);
int     game_player2(char **map, int pid);
int                     waiting(char **map, int win, int *lose, int pid);
int                     touched_player2(char **map, char *shoot,
                                        int *win);
/* connected_or_not.c */
int	connected_or_not(int pid);

/* receive_signal.c */
int     receive_signal(char **map , int *lose);
int     receive_signal_2(char **map , int *lose);
char    *put_in_pos();

/* send_signal.c */
int     send_signal(char **map, char *shot, int *win, int *lose);
int     init_sig();
int     send_sig(char *pos);
int     touched_or_not(char **map, char *shoot, int *win, int *lose);
int     free_them(char *shoot, char *x, char *y);
void    signal2(__attribute__((unused)) int sig, siginfo_t *info,
		__attribute__((unused)) void *nothing);
void    signal1(__attribute__((unused)) int sig, siginfo_t *info,
		__attribute__((unused)) void *nothing);

/* send_signal_2.c */
int     send_signal_2(char **map, char *shoot, int *win);
int     touched_or_not_2(char **map, char *shoot, int *win);

/* touched_and_wait.c */
void                 touched_sig(__attribute__((unused)) int sig,
				 siginfo_t *info, __attribute__((unused)) void *nothing);
void                 missed_sig(__attribute__((unused)) int sig,
				siginfo_t *info, __attribute__((unused)) void *nothing);
int                     map_after(char **map, char *shoot, int *win);

/* wait_player2.c */
int                     check_his_shot(char **map, int *lose, int ix, int iy);
char                    *catch(int pid);

#endif /* !MY_H_ */
