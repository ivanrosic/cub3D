/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:43:02 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/26 17:55:01 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_next_line_cut(size_t i, char **line, char *str)
{
	if (i == 0)
		*line = ft_strdup("");
	else
		*line = ft_substr(str, 0, i);
	str[0] = '\0';
}

char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
