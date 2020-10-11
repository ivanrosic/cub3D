/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:17:43 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/26 17:46:39 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;
	size_t		tmp;

	i = 0;
	tmp = ft_strlen(s1);
	if (!(str = malloc(sizeof(*str) * (tmp + 1))))
		return (NULL);
	while (i < tmp)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
