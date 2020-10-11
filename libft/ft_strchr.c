/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 16:44:06 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 15:16:48 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*s1;

	s1 = (char *)s;
	a = c;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == a)
			return (&s1[i]);
		i++;
	}
	if (c == '\0')
		return (&s1[i]);
	return (NULL);
}
