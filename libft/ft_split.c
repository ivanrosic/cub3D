/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 20:42:25 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 23:29:03 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_sep(char c, char s)
{
	if (c == s)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static char			*ft_copy(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (ft_is_sep(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int			ft_size(const char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 1;
	while (str[i])
	{
		if (ft_is_sep(str[i], c) == 0 &&
				(ft_is_sep(str[i + 1], c) == 1))
			word++;
		i++;
	}
	return (word);
}

static int			ft_cpy_tab(char **split, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_sep(str[i + j], c) == 0)
				j++;
			if (!(split[k] = malloc(sizeof(char) * (j + 1))))
				return (0);
			ft_copy(split[k], str + i, c);
			i = i + j;
			k++;
		}
	}
	split[k] = 0;
	return (1);
}

char				**ft_split(const char *s, char c)
{
	int		i;
	char	*str;
	char	**split;

	i = 0;
	str = (char *)s;
	if (!(split = malloc(sizeof(char *) * (ft_size(s, c) + 1))))
		return (0);
	if (!(ft_cpy_tab(split, str, c)))
	{
		while (split[i++])
			free(split[i]);
		free(split);
		return (NULL);
	}
	return (split);
}
