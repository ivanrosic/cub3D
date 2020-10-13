/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_open.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/09/12 22:19:35 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/10/13 04:15:43 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int ft_is_mapar (char *str)
{
	if(str[0] == 'R')
		return(0)
	if(str[0] == 'N' && )
		return(0)
	if(str[0] == 'R')
		return(0)
	if(str[0] == 'R')
		return(0)
	}

int ft_open(char **av, t_parse *parse)
{
	int fd;
	char *str;
	int ret;

	ret = 1;
	str = 0;
	if (!(fd = open(av[1], O_RDONLY)))
	{
		printf("problem with opening .cub ");
		return (-1);
	}
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
			return(-1);
		if(ft_is_map == 0)
		parse->str = ft_strjoin_f(parse->str, str);
	}
	dprintf(1, "test:<%s>", parse->str);
	return (0);
}
