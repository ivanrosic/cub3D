/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 19:53:13 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 14:27:37 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char a;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	a = (unsigned char)c;
	while (n > 0)
	{
		*d = *s;
		if (*d == a)
		{
			d++;
			return (d);
		}
		d++;
		s++;
		n--;
	}
	return (NULL);
}
