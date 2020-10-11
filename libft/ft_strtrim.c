/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 08:16:27 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 17:18:58 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin(char const *s1, char const *set)
{
	int i;
	int c;
	int j;

	i = 0;
	c = 1;
	while (s1[i] != '\0' && c != 0)
	{
		c = 0;
		j = 0;
		while (set[j] != '\0' && c == 0)
		{
			if (s1[i] == set[j])
				c++;
			j++;
		}
		if (c != 0)
			i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	int i;
	int c;
	int j;

	i = ft_strlen(s1) - 1;
	c = 1;
	while (i > 0 && (s1[i] != 0 && c != 0))
	{
		c = 0;
		j = 0;
		while (set[j] != '\0' && c == 0)
		{
			if (s1[i] == set[j])
				c++;
			j++;
		}
		if (c != 0)
			i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	begin;
	size_t	i;

	i = 0;
	end = ft_end(s1, set);
	begin = ft_begin(s1, set);
	if (end < begin)
		return (ft_strdup("\0"));
	if (!(str = malloc(sizeof(*str) * end - begin + 2)))
		return (NULL);
	while (begin <= end)
	{
		str[i] = s1[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}
