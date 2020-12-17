/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_on_mlx.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/12/17 15:59:12 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 16:04:31 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_init_begin(t_mmlx *mmlx, int x)
{
	mmlx->camera_x = (double)(2 * (double)((double)x / mmlx->res_x)) - 1;
	mmlx->raydir_x = mmlx->direction_x + mmlx->plane_x * mmlx->camera_x;
	mmlx->raydir_y = mmlx->direction_y + mmlx->plane_y * mmlx->camera_x;
	mmlx->deltadist_x = fabs(1 / mmlx->raydir_x);
	mmlx->deltadist_y = fabs(1 / mmlx->raydir_y);
	mmlx->hit = 0;
	mmlx->map_x = (int)mmlx->pos_x;
	mmlx->map_y = (int)mmlx->pos_y;
}

void	ft_init_side_dist(t_mmlx *mmlx)
{
	if (mmlx->raydir_x < 0)
	{
		mmlx->step_x = -1;
		mmlx->sidedist_x = (mmlx->pos_x - mmlx->map_x) * mmlx->deltadist_x;
	}
	else
	{
		mmlx->step_x = 1;
		mmlx->sidedist_x = (mmlx->map_x + 1.0 - mmlx->pos_x) * mmlx->deltadist_x;
	}
	if (mmlx->raydir_y < 0)
	{
		mmlx->step_y = -1;
		mmlx->sidedist_y = (mmlx->pos_y - mmlx->map_y) * mmlx->deltadist_y;
	}
	else
	{
		mmlx->step_y = 1;
		mmlx->sidedist_y = (mmlx->map_y + 1.0 - mmlx->pos_y) * mmlx->deltadist_y;
	}
}
