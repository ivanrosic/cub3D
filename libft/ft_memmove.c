/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 19:57:57 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 15:12:53 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = dst;
	s = src;
	if (src >= dst)
		ft_memcpy(d, s, len);
	else
	{
		s = s + len;
		d = d + len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
