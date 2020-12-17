/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/12/17 15:40:38 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 16:22:45 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_exit(int key, t_mmlx *mmlx)
{
	dprintf(1, "key:%d\n", key);
	if (key == 65307)
		exit(0);
	return (0);
}

int		ft_key_move_press(int key, t_mmlx *mmlx)
{
	dprintf(1, "key:%d\n", key);
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
	{
		if (mmlx->map[(int)mmlx->pos_y][(int)(mmlx->pos_x + 0.5 * mmlx->direction_y)] == 48)
			mmlx->pos_x += 0.25 * mmlx->direction_y;
		if (mmlx->map[(int)(mmlx->pos_y - 0.5 * mmlx->direction_x)][(int)mmlx->pos_x] == 48)
			mmlx->pos_y -= 0.25 * mmlx->direction_x;
	}
	else if (key == 100)
	{
		if (mmlx->map[(int)mmlx->pos_y][(int)(mmlx->pos_x - 0.5 * mmlx->direction_y)] == 48)
			mmlx->pos_x -= 0.25 * mmlx->direction_y;
		if (mmlx->map[(int)(mmlx->pos_y + 0.5 * mmlx->direction_x)][(int)mmlx->pos_x] == 48)
			mmlx->pos_y += 0.25 * mmlx->direction_x;
	}
	if (key == 115)
	{
		if (mmlx->map[(int)mmlx->pos_y][(int)(mmlx->pos_x - 0.5 * mmlx->direction_x)] == 48)
			mmlx->pos_x -= 0.25 * mmlx->direction_x;
		if (mmlx->map[(int)(mmlx->pos_y - 0.5 * mmlx->direction_y)][(int)mmlx->pos_x] == 48)
			mmlx->pos_y -= 0.25 * mmlx->direction_y;
	}
	else if (key == 119)
	{
		if (mmlx->map[(int)mmlx->pos_y][(int)(mmlx->pos_x + 0.5 * mmlx->direction_x)] == 48)
			mmlx->pos_x += 0.25 * mmlx->direction_x;
		if (mmlx->map[(int)(mmlx->pos_y + 0.5 * mmlx->direction_y)][(int)mmlx->pos_x] == 48)
			mmlx->pos_y += 0.25 * mmlx->direction_y;
	}
	return (0);
}

void	ft_key_press(t_mmlx *mmlx)
{
	mlx_hook(mmlx->win, 2, 0, ft_key_move_press, mmlx);
	//mlx_hook(mmlx->win, 3, 0, ft_key_move_release, mmlx);
	mlx_hook(mmlx->win, 17, 0, ft_exit, mmlx);
}
