/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 17:52:00 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 15:20:27 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)haystack;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (haystack[i] == '\0')
		return (0);
	while ((haystack[i] != '\0') && (len > i))
	{
		if (haystack[i] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (&str[i - j + 1]);
		i++;
		if (haystack[i] != needle[j])
			j = 0;
	}
	return (0);
}
