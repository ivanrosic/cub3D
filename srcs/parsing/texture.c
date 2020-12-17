/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/12/17 15:48:01 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 16:26:15 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_calcul_draw(t_mmlx *mmlx)
{
	mmlx->lineheight = (int)(mmlx->res_y / mmlx->wall_dist);
	mmlx->drawstart = (-mmlx->lineheight / 2) + (mmlx->res_y / 2);
	mmlx->drawend = (mmlx->lineheight / 2) + (mmlx->res_y / 2);
	if (mmlx->drawstart < 0)
		mmlx->drawstart = 0;
	if (mmlx->drawend >= mmlx->res_y)
	{
		mmlx->drawend = mmlx->res_y - 1;
	}
}

void	ft_calc_text(int x, t_mmlx *mmlx, double wall_x, int nbimg)
{
	double	step;
	double	texpos;
	int		texx;
	int		texy;
	int		y;

	y = mmlx->drawstart;
	step = 1.0 * mmlx->img[nbimg].height / mmlx->lineheight;
	texpos = (mmlx->drawstart - mmlx->res_y / 2 + mmlx->lineheight / 2) * step;
	texx = (int)(wall_x * mmlx->img[nbimg].width);
	if (mmlx->side == 0 && mmlx->raydir_x > 0)
		texx = mmlx->img[nbimg].width - texx - 1;
	if (mmlx->side == 1 && mmlx->raydir_y < 0)
		texx = mmlx->img[nbimg].width - texx - 1;
	while (y < mmlx->drawend)
	{
		if (texpos > (mmlx->img[nbimg].height - 1))
			texy = mmlx->img[nbimg].height - 1;
		else
			texy = texpos;
		texpos += step;
		mmlx->data_adress[x + y * mmlx->res_x] = mmlx->img[nbimg].data[texx + texy * mmlx->img[nbimg].width];
		y++;
	}
}

void	ft_ew_text(int x, t_mmlx *mmlx)
{
	double wall_x;

	wall_x = mmlx->pos_y + mmlx->wall_dist * mmlx->raydir_y;
	wall_x -= floor(wall_x);
	if (mmlx->map_x < mmlx->pos_x)
		ft_calc_text(x, mmlx, wall_x, 2);
	else
		ft_calc_text(x, mmlx, wall_x, 3);
}

void	ft_ns_text(int x, t_mmlx *mmlx)
{
	double wall_x;

	wall_x = mmlx->pos_x + mmlx->wall_dist * mmlx->raydir_x;
	wall_x -= floor(wall_x);
	if (mmlx->map_y < mmlx->pos_y)
		ft_calc_text(x, mmlx, wall_x, 0);
	else
		ft_calc_text(x, mmlx, wall_x, 1);
}

void	ft_verline(int x, t_mmlx *mmlx)
{
	int start;
	int zero;

	zero = 0;
	start = mmlx->drawstart;
	while (zero <= start)
	{
		mmlx->data_adress[(x) + (zero * mmlx->res_x)] = 0x0025FDE9;
		zero++;
	}
	if (mmlx->side == 1)
	{
		ft_ns_text(x, mmlx);
	}
	else
	{
		ft_ew_text(x, mmlx);
	}
	start = mmlx->drawend;
	while (start <= mmlx->res_y)
	{
		mmlx->data_adress[(x) + (start * mmlx->res_x)] = 0x00FFFFFF;
		start++;
	}
}
