/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/09/12 14:42:22 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 15:54:07 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"


void	ft_free_for_exit_parse(t_parse *parse)
{
	if(!(parse))
	{
		if(!(parse->str))
			free(parse->str);
		if(!(parse->pc))
		{
			if(!(parse->pc[0]))
				free(parse->pc[0]);
			if(!(parse->pc[1]))
				free(parse->pc[1]);
			if(!(parse->pc[2]))
				free(parse->pc[2]);
			if(!(parse->pc[3]))
				free(parse->pc[3]);
		free(parse->pc);
		}
		if(!(parse->sprite))
			free(parse->sprite);
		free(parse);
	}
}

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

void	ft_load_texture(t_parse *parse,t_mmlx *mmlx)
{
	mmlx->img[0].image = mlx_xpm_file_to_image(mmlx->mlx, parse->pc[0], &mmlx->img[0].width, &mmlx->img[0].height);
	mmlx->img[1].image = mlx_xpm_file_to_image(mmlx->mlx, parse->pc[1], &mmlx->img[1].width, &mmlx->img[1].height);
	mmlx->img[2].image = mlx_xpm_file_to_image(mmlx->mlx, parse->pc[2], &mmlx->img[2].width, &mmlx->img[2].height);
	mmlx->img[3].image = mlx_xpm_file_to_image(mmlx->mlx, parse->pc[3], &mmlx->img[3].width, &mmlx->img[3].height);
	mmlx->img[0].data = (int *)mlx_get_data_addr(mmlx->img[0].image, &mmlx->img[0].bpp, &mmlx->img[0].size_line, &mmlx->img[0].endian);
	mmlx->img[1].data = (int *)mlx_get_data_addr(mmlx->img[1].image, &mmlx->img[1].bpp, &mmlx->img[1].size_line, &mmlx->img[1].endian);
	mmlx->img[3].data = (int *)mlx_get_data_addr(mmlx->img[3].image, &mmlx->img[3].bpp, &mmlx->img[3].size_line, &mmlx->img[3].endian);
	mmlx->img[2].data = (int *)mlx_get_data_addr(mmlx->img[2].image, &mmlx->img[2].bpp, &mmlx->img[2].size_line, &mmlx->img[2].endian);
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
	ft_load_texture(parse, mmlx);
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

