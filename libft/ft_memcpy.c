/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:08:49 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 01:32:01 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				l;

	if (dst == NULL && src == NULL)
		return (NULL);
	l = (int)n;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (l > 0)
	{
		*d = *s;
		s++;
		d++;
		l--;
	}
	return (dst);
}
