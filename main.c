/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivanrosic <ivanrosic@student.le-101>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/06/18 17:45:43 by ivanrosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/11/29 01:07:17 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/cub.h"

int main(int ac, char **av)
{
	t_parse *parse;

	parse = malloc(sizeof(t_parse));
	ft_init_struct(parse);
	if(ft_parse(ac, av, parse) < 0)
		return(-1);
	ft_map_char_to_int(parse);
	ft_open_window(parse);
	return(0);
}
