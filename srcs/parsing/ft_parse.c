/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/07/24 04:07:59 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/10/27 00:58:24 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int ft_error_before_open(int ac, char **av)
{
	int i;

	if (ac == 1)
	{
		printf("not enough argument\n");
		return(-1);
	}
	if (ac > 2)
	{
		printf("too much argument\n");
		return(-1);
	}
	i = ft_strlen(av[1]) - 4;
	if (!(i > 0 && av[1][i] == '.' && av[1][i + 1] == 'c' &&
		av[1][i + 2] == 'u' && av[1][i + 3] == 'b'))
		{
		printf("map in .cub waited\n");
		return(-1);
	}
	return(0);
}

int	ft_parse(int ac, char **av, t_parse *parse)
{
	if(ft_error_before_open(ac, av) < 0)
		return(-1);
	if(ft_open(av, parse) <= 0)
		printf("test");//ft_open_window(parse);
	else
		{
		printf("error1\n");
		return(-1);
		}
	return(0);
}
