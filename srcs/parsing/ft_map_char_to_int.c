/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map_char_to_int.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: user42 <user42@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/10/27 00:42:36 by user42       #+#   ##    ##    #+#       */
/*   Updated: 2020/12/17 14:41:49 by ivarosic         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_map_char_to_int(t_parse *parse)
{
	int i;
	int a;
	int b;

	b = 0;
	a = 0;
	i = 0;
	parse->map = malloc(sizeof(parse->map) * parse->nb_line);
	while(parse->str[i] != '\0')
	{
		if(parse->str[i] == 'N' || parse->str[i] == 'S' || parse->str[i] == 'S' || parse->str[i] == 'S')
			parse->str[i] = 32)
		if(a == 0)
			parse->map[b] = malloc(sizeof(int) * parse->nb_max_line);
		if(parse->str[i] == 10)
		{
			while(a < parse->nb_max_line)
				parse->map[b][a++] = 32;
			b++;
			a = 0;
		}
		else
			parse->map[b][a++] = (int)parse->str[i];
		i++;
	}
	return(0);
}
