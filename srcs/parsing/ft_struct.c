/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/09/12 14:42:22 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/11/29 01:05:36 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"


void	ft_init_dir(char pos, t_mmlx *mmlx)
{
	if(pos == 'N')
		mmlx->angle = M_PI_2;
	else if (pos == 'S')
		mmlx->angle = -M_PI_2;
	else if (pos == 'E')
		mmlx->angle = 0;
	else if (pos == 'W')
		mmlx->angle = M_PI;
	ft_angle_to_dir(mmlx);
}

void	ft_init_mlx_struct(t_parse *parse,t_mmlx *mmlx)
{
	mmlx->map = parse->map;
	mmlx->res_x = parse->res_x;
	mmlx->res_y = parse->res_y;
	mmlx->pos_x = parse->pos_player_x;
	mmlx->pos_y = parse->pos_player_y;
	ft_init_dir(parse->pos, mmlx);
	mmlx->mlx = mlx_init();
	mmlx->image = mlx_new_image(mmlx->mlx, parse->res_x, parse->res_y);
mmlx->data_adress = (int *)mlx_get_data_addr(mmlx->image, &mmlx->bpp, &mmlx->sl, &mmlx->endian);
	mmlx->win = mlx_new_window(mmlx->mlx, parse->res_x, parse->res_y,"Raycaster");
}

void	ft_init_struct(t_parse *parse)
{	
	parse->str = ft_strdup("");
	parse->res_x = 0;
	parse->res_y = 0;
	parse->pc = malloc(sizeof(parse->pc) * 4);
	parse->pc[0] = ft_strdup("");
	parse->pc[1] = ft_strdup("");
	parse->pc[2] = ft_strdup("");
	parse->pc[3] = ft_strdup("");
	parse->sprite = ft_strdup("");
	parse->nb_line = 0;
	parse->nb_max_line = 0;
	parse->pos_player_x = 0;
	parse->pos_player_y = 0;
}

