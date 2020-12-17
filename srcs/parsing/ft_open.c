/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_open.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/09/12 22:19:35 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 16:13:43 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_ignore_num(char *str, int i)
{
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		ft_ignore_space(char *str, int i)
{
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\f')
			|| (str[i] == '\r') || (str[i] == ' '))
		i++;
	return (i);
}

int		ft_res(char *str, int i, t_parse *parse)
{
	i = ft_ignore_space(str, i);
	parse->res_x = ft_atoi(&str[i]);
	i = ft_ignore_num(str, i);
	parse->res_y = ft_atoi(&str[i]);
	return (1);
}

int		ft_fill_pc(char *str, int pc, t_parse *parse, int i)
{
	i = ft_ignore_space(str, i);
	if (pc != 4)
		parse->pc[pc] = ft_strjoin_f(parse->pc[pc], &str[i]);
	else
		parse->sprite = ft_strjoin_f(parse->sprite, &str[i]);
	return (pc + 2);
}

int		ft_colors(char *str, int fc, t_parse *parse, int i)
{
	i = ft_ignore_space(str, i);
	parse->fc[fc][0] = ft_atoi(&str[i]);
	i = ft_ignore_num(str, i) + 1;
	i = ft_ignore_space(str, i);
	parse->fc[fc][1] = ft_atoi(&str[i]);
	i = ft_ignore_num(str, i) + 1;
	i = ft_ignore_space(str, i);
	parse->fc[fc][2] = ft_atoi(&str[i]);
	return (fc + 7);
}

int		ft_verif_map(t_parse *parse, char *str)
{
	int i;

	i = 0;
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			parse->pos = str[i];
			parse->pos_player_x = i;
			parse->pos_player_y = parse->nb_line;
		}
		i++;
	}
	parse->nb_line++;
	if (i > parse->nb_max_line)
		parse->nb_max_line = i;
	return (1);
}

int		ft_is_map(char *str, t_parse *parse)
{
	int i;

	i = ft_ignore_space(str, 0);
	if (str[i] != '\0')
	{
		if (str[i] == 'R')
			return (ft_res(str, i + 1, parse));
		else if (str[i] == 'S' && str[i + 1] != 'O')
			return (ft_fill_pc(str, 4, parse, i + 1));
		else if (str[i] == 'F')
			return (ft_colors(str, 0, parse, i + 1));
		else if (str[i] == 'C')
			return (ft_colors(str, 1, parse, i + 1));
		else if (str[i] == 'N' && str[i + 1] == 'O')
			return (ft_fill_pc(str, 0, parse, i + 2));
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (ft_fill_pc(str, 1, parse, i + 2));
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (ft_fill_pc(str, 2, parse, i + 2));
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (ft_fill_pc(str, 3, parse, i + 2));
	}
	if (ft_verif_map(parse, str) == 0)
		return (-1);
	return (0);
}

int		ft_open(char **av, t_parse *parse)
{
	int		fd;
	char	*str;
	int		ret;

	ret = 1;
	str = 0;
	if (!(fd = open(av[1], O_RDONLY)))
	{
		printf("problem with opening .cub");
		return (-1);
	}
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
			return (-1);
		if (ft_is_map(str, parse) == 0)
			parse->str = ft_strjoin_f(parse->str, ft_strjoin(str, "\n"));
	}
	return (0);
}
