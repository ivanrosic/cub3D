/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/10/26 19:45:22 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/10/28 03:21:21 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int  ft_exit(int key, t_mmlx *mmlx)
{
	(void)mmlx;
	dprintf(1, "key:%d\n", key);
	if (key == 65307)
		exit(0);
	return(0);
}

void	ft_init_side_dist(t_mmlx *mmlx)
{
	if(mmlx->raydir_x < 0)
	{
		mmlx->step_x = -1;
		mmlx->sidedist_x = (mmlx->pos_x - mmlx->map_x) * mmlx->deltadist_x;
	}
	else
	{
		mmlx->step_x = 1;
		mmlx->sidedist_x = (mmlx->map_x + 1.0 - mmlx->pos_x) * mmlx->deltadist_x;
	}
	if(mmlx->raydir_y < 0)
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

void	ft_hit(t_mmlx *mmlx)
{
	while(hit == 0)
	{
		if(mmlx->sidedist_x < mmlx->sidedist_y)
		{
			mmlx->sidedist_x += mmlx
		}
	}
}

int ft_fct(t_mmlx *mmlx)
{
	int x;
	
	x = 0;
	while(x < mmlx->res_x)
	{
		mmlx->camera_x =(double)(2 *(double)((double)x/ mmlx->res_x)) - 1;
		mmlx->raydir_x = mmlx->direction_x + mmlx->plane_x * mmlx->camera_x;
		mmlx->raydir_y = mmlx->direction_y + mmlx->plane_y * mmlx->camera_x;
		mmlx->deltadist_x = fabs(1 / mmlx->raydir_x);
		mmlx->deltadist_y = fabs(1 / mmlx->raydir_y);
		mmlx->hit = 0;
		mmlx->map_x = (int)mmlx->pos_x;
		mmlx->map_y = (int)mmlx->pos_y;
		ft_init_side_dist(mmlx);
		ft_hit(mmlx);
		x++;
		}
	//	mmlx->data_adress[50000 + i] = 0x00ff00;
	mlx_put_image_to_window(mmlx->mlx, mmlx->win, mmlx->image, 0, 0);
	return (0);	
}

void	ft_open_window(t_parse *parse)
{
	t_mmlx *mmlx;

	mmlx = malloc(sizeof(t_mmlx));
	ft_init_mlx_struct(parse, mmlx);
	dprintf(1, "pos:%f\n", mmlx->pos_x);
	dprintf(1, "pos:%f\n", mmlx->pos_y);
	mlx_hook(mmlx->win, 2, (1L << 0), ft_exit, mmlx);
	mlx_loop_hook(mmlx->mlx, ft_fct, mmlx);
	mlx_loop(mmlx->mlx); 
}
