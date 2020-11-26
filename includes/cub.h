/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivanrosic <ivanrosic@student.le-101>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/26 12:34:49 by ivanrosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/11/19 22:16:27 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libmlx/mlx.h"

typedef struct	s_parse
{	
	char *str;
	int res_x;
	int res_y;
	char **pc;
	char *sprite;
	int fc[2][3];
	int	**map;
	int nb_line;
	int nb_max_line;
	int pos_player_x;
	int pos_player_y;
	char pos;
}				t_parse;

typedef struct	s_mmlx
{
	int **map;
	int res_x;
	int res_y;
	void *mlx;
	void *win;
	int loop;
	int loop_hook;
	void *image;
	int *data_adress;
	int bpp;
	int sl;
	int endian;
	double pos_x;
	double pos_y;
	int	map_x;
	int map_y;
	double direction_x;
	double direction_y;
	double angle;
	double plane_x;
	double plane_y;
	double sidedist_x;
	double sidedist_y;
	double deltadist_x;
	double deltadist_y;
	double raydir_x;
	double raydir_y;
	double camera_x;
	double wall_dist;
	int step_y;
	int step_x;
	int hit;
	int lineheight;
	int drawstart;
	int drawend;
	int xpos;
	int side;
	char n[9];
	char s[9];
	char e[9];
	char w[9];


	}			t_mmlx;

int		ft_parse(int ac, char **av, t_parse *parse);
void	ft_init_struct(t_parse *parse);
void	ft_init_mlx_struct(t_parse *parse, t_mmlx *mmlx);
int		ft_open(char **av, t_parse *parse);
char	*ft_strjoin_f(char *s1, char const *s2);
void	ft_open_window(t_parse *parse);
int ft_map_char_to_int(t_parse *parse);
void	ft_angle_to_dir(t_mmlx *mmlx);


#endif
