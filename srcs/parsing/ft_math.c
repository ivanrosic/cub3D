/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_math.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/10/27 14:15:06 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/11/26 18:25:25 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_angle_to_plane(t_mmlx *mmlx)
{
		mmlx->plane_x=cos(mmlx->angle - M_PI_2);
		mmlx->plane_y=-1*sin(mmlx->angle - M_PI_2);
	}

void	ft_angle_to_dir(t_mmlx *mmlx)
{
		mmlx->direction_x=cos(mmlx->angle);
		mmlx->direction_y=-1*sin(mmlx->angle);
		ft_angle_to_plane(mmlx);
}
