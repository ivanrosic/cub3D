/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/10/26 19:45:22 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 16:08:30 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_hit(t_mmlx *mmlx)
{
	while (mmlx->hit == 0)
	{
		if (mmlx->sidedist_x < mmlx->sidedist_y)
		{
			mmlx->sidedist_x += mmlx->deltadist_x;
			mmlx->map_x += mmlx->step_x;
			mmlx->side = 0;
		}
		else
		{
			mmlx->sidedist_y += mmlx->deltadist_y;
			mmlx->map_y += mmlx->step_y;
			mmlx->side = 1;
		}
		if (mmlx->map[mmlx->map_y][mmlx->map_x] > 48)
			mmlx->hit = 1;
	}
}

void	ft_walldist(t_mmlx *mmlx)
{
	if (mmlx->side == 0)
		mmlx->wall_dist = (mmlx->map_x - mmlx->pos_x + (1 - mmlx->step_x) / 2) / mmlx->raydir_x;
	else
		mmlx->wall_dist = (mmlx->map_y - mmlx->pos_y + (1 - mmlx->step_y) / 2) / mmlx->raydir_y;
}

int		ft_fct(t_mmlx *mmlx)
{
	int x;

	x = 0;
	while (x < mmlx->res_x)
	{
		ft_init_begin(mmlx, x);
		ft_init_side_dist(mmlx);
		ft_hit(mmlx);
		ft_walldist(mmlx);
		ft_calcul_draw(mmlx);
		ft_verline(x, mmlx);
		x++;
	}
	mlx_put_image_to_window(mmlx->mlx, mmlx->win, mmlx->image, 0, 0);
	return (0);
}

void	ft_open_window(t_parse *parse)
{
	t_mmlx *mmlx;

	mmlx = malloc(sizeof(t_mmlx));
	ft_init_mlx_struct(parse, mmlx);
	ft_key_press(mmlx);
	mlx_loop_hook(mmlx->mlx, ft_fct, mmlx);
	mlx_loop(mmlx->mlx);
}
