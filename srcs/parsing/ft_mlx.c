/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/10/26 19:45:22 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/11/29 01:05:34 by user42      ###    #+. /#+    ###.fr     */
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
	if (key == 65361)
	{
		mmlx->angle = mmlx->angle + 0.1;
		ft_angle_to_dir(mmlx);
	}
	else if (key == 65363)
	{
		mmlx->angle = mmlx->angle - 0.1;
		ft_angle_to_dir(mmlx);
	}
	if (key == 97)
		mmlx->pos_x = mmlx->pos_x - 0.1;
	else if (key == 100)
		mmlx->pos_x = mmlx->pos_x + 0.1;
	if (key == 115)
	{
		mmlx->pos_y = mmlx->pos_y + 0.3;
	}
	else if (key == 119)
	{
		mmlx->pos_y = mmlx->pos_y - 0.1;
	}
	return(0);
}

void	ft_init_begin(t_mmlx *mmlx, int x)
{
	mmlx->camera_x =(double)(2 *(double)((double)x / mmlx->res_x)) - 1;
	mmlx->raydir_x = mmlx->direction_x + mmlx->plane_x * mmlx->camera_x;
	mmlx->raydir_y = mmlx->direction_y + mmlx->plane_y * mmlx->camera_x;
	mmlx->deltadist_x = fabs(1 / mmlx->raydir_x);
	mmlx->deltadist_y = fabs(1 / mmlx->raydir_y);
	mmlx->hit = 0;
	mmlx->map_x = (int)mmlx->pos_x;
	mmlx->map_y = (int)mmlx->pos_y;
	//dprintf(1,"posx-y = %f; %f\ndirectionx-y = %f; %f\nplanex-y = %f; %f\n", mmlx->pos_x, mmlx->pos_y, mmlx->direction_x, mmlx->direction_y, mmlx->plane_x, mmlx->plane_y);
	//dprintf(1,"deltadistx-y = %f; %f\nmapx-y  = %d; %d\n", mmlx->deltadist_x, mmlx->deltadist_y, mmlx->map_x, mmlx->map_y);
	//dprintf(1,"x = %d\ncamerax = %f\nraydirx-y = %f; %f\n", x, mmlx->camera_x, mmlx->raydir_x, mmlx->raydir_y);
	//dprintf(1,"deltadistx-y = %f; %f\nmapx-y  = %d; %d\n", mmlx->deltadist_x, mmlx->deltadist_y, mmlx->map_x, mmlx->map_y);
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
	//dprintf(1,"sidedistx-y = %f; %f\nstepx-y  = %d; %d\n", mmlx->sidedist_x, mmlx->sidedist_y, mmlx->step_x, mmlx->step_y);

}

void	ft_hit(t_mmlx *mmlx)
{
	while(mmlx->hit == 0)
	{
		if(mmlx->sidedist_x < mmlx->sidedist_y)
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
		if(mmlx->map[mmlx->map_y][mmlx->map_x] > 48)
			mmlx->hit = 1;
	}
	//dprintf(1,"(2)sidedistx-y = %f; %f\n(2)mapx-y  = %d; %d\n", mmlx->sidedist_x, mmlx->sidedist_y, mmlx->map_x, mmlx->map_y);
	//dprintf(1,"map[mapy][mapx] = %d\n", mmlx->map[mmlx->map_y][mmlx->map_x]);
}

void	ft_walldist(t_mmlx *mmlx)
{
	//dprintf(1, "side = %d\n", mmlx->side);
	//dprintf(1, "mapy = %d\nposy = %f\nstepy = %d\nraydiry = %f\n", mmlx->map_y, mmlx->pos_y, mmlx->step_y, mmlx->raydir_y);
	if(mmlx->side == 0)
		mmlx->wall_dist = (mmlx->map_x - mmlx->pos_x + (1 - mmlx->step_x) / 2) / mmlx->raydir_x;
	else
		mmlx->wall_dist = (mmlx->map_y - mmlx->pos_y + (1 - mmlx->step_y) / 2) / mmlx->raydir_y;
	//dprintf(1, "walldist = %f\n", mmlx->wall_dist);
}

void	ft_calcul_draw(t_mmlx *mmlx)
{
	mmlx->lineheight = (int)(mmlx->res_y / mmlx->wall_dist);
	mmlx->drawstart = (-mmlx->lineheight / 2) + (mmlx->res_y / 2);
	if(mmlx->drawstart < 0)
		mmlx->drawstart = 0;
	mmlx->drawend = (mmlx->lineheight / 2) + (mmlx->res_y / 2);
	if(mmlx->drawend >= mmlx->res_y)
	{	mmlx->drawend = mmlx->res_y - 1;}

}

void	ft_set_colors(t_mmlx *mmlx)
{
	mmlx->n = 0x800080;
	mmlx->s = 0xFF0000;
	mmlx->e = 0x00FF00;
	mmlx->w = 0x0000FF;


}

void	ft_calc_text(int x, t_mmlx *mmlx, double wall_x, int *data)
{
	double step;
	double texpos;
	int texx;
	int texy;
	int y;

	y = mmlx->drawstart;
	step = 1.0 * mmlx->textheight / mmlx->lineheight;
	texpos = (mmlx->drawstart - mmlx->res_y / 2 + mmlx->lineheight / 2) * step;
	texx = int(wall_x * texwidth);
	if(side == 0 && mmlx->raydir_x > 0)
		texx = texwidth - texx - 1;
	if(side == 1 && mmlx->raydir_y < 0)
		texx = texwidth - texx - 1;
	while(y < mmlx->drawend)
	{	
		if(texpos > (mmlx->texheight - 1))
			texy = textheight - 1;
		else
			texy = texpos;
		texpos += step;
		mmlx->data_adress[x + y * mmlx->res_x] = data[texx + texy * mmlx->texwidth];
		y++;
	}
}

void	ft_ew_text(int x, t_mmlx *mmlx)
{
	double wall_x;

	wall_x = mmlx->pos_y + mmlx->wall_dist * mmlx->ray_dir_y;
	wall_x -= floor(mmlx->wall_x);

	if (mmlx->map_x < mmlx->pos_x)
		ft_calc_text(x, mmlx, wall_x,mmlx->ndata);
	else
		ft_calc_text(x, mmlx, wall_x,mmlx->sdata);
}

void	ft_ns_text(int x, t_mmlx *mmlx)
{
	double wall_x;

	wall_x = mmlx->pos_x + mmlx->wall_dist * mmlx->ray_dir_x;
	wall_x -= floor(mmlx->wall_x);

	if (mmlx->map_y < mmlx->pos_y)
		ft_calc_text(x, mmlx, wall_x,mmlx->ndata);
	else
		ft_calc_text(x, mmlx, wall_x,mmlx->sdata);
}

void	ft_verline(int x, t_mmlx *mmlx)
{
	int start;
	int zero = 0;

	start = mmlx->drawstart;
	while(zero <= start)
	{
		mmlx->data_adress[(x) + (zero * mmlx->res_x)] = 0x00000000;
		zero++;
	}
	while(start <= mmlx->drawend)
	{
		if (mmlx->side == 1)
		{
			ft_ns_text(x, mmlx);
			/*if (mmlx->map_y < mmlx->pos_y)
			mmlx->data_adress[(x) + (start * mmlx->res_x)] = mmlx->n;
			else
				mmlx->data_adress[(x) + (start * mmlx->res_x)] = mmlx->s;
			*/
		}
		else
		{
			ft_ew_text(x, mmlx);
		}
	}
	start = mmlx->drawend;
	while(start <= mmlx->res_y)
	{
		mmlx->data_adress[(x) + (start * mmlx->res_x)] = 0x00FFFFFF;
		//mlx_pixel_put(mmlx->mlx, mmlx->win, x, start, 0x00FFFFFF);
		start++;
	}
}

int ft_fct(t_mmlx *mmlx)
{
	int x;

	x = 0;
	while(x < mmlx->res_x)
	{
		ft_init_begin(mmlx, x);
		ft_init_side_dist(mmlx);
		ft_hit(mmlx);
		ft_walldist(mmlx);
		ft_calcul_draw(mmlx);
		ft_verline(x, mmlx);
		x++;
	}
	mlx_put_image_to_window(mmlx->mlx, mmlx->win, mmlx->image,0,0);
	return (0);	
}

void	ft_open_window(t_parse *parse)
{
	t_mmlx *mmlx;

	mmlx = malloc(sizeof(t_mmlx));
	ft_init_mlx_struct(parse, mmlx);
	ft_set_colors(mmlx);
	mlx_hook(mmlx->win, 2, (1L << 0), ft_exit, mmlx);
	mlx_loop_hook(mmlx->mlx, ft_fct, mmlx);
	mlx_loop(mmlx->mlx); 
}
