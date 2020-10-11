/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 06:04:13 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 23:28:18 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	sep(char c, char s)
{
	if (c == '\0')
		return (0);
	if (s == c)
		return (0);
	return (1);
}

static int	nb_word(char const *str, char charset)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (sep(str[i], charset) == 0)
		{
			if (str[i] == '\0')
				return (cpt);
			i++;
		}
		while (sep(str[i], charset) == 1)
		{
			cpt++;
			i++;
			while (sep(str[i], charset) == 1)
				i++;
		}
		if (str[i] == '\0')
			return (cpt);
		i++;
	}
	return (cpt);
}

static int	ft_word_malloc(char **split, char const *str, int tab[3])
{
	char	*word;
	int		len;
	int		k;

	len = tab[2] - tab[1] + 1;
	if (!(word = malloc(sizeof(*word) * len)))
	{
		free(word);
		return (-1);
	}
	k = 0;
	while (k < len - 1)
	{
		word[k] = str[tab[1]];
		tab[1]++;
		k++;
	}
	word[k] = '\0';
	split[tab[0]] = word;
	tab[0]++;
	split[tab[0]] = NULL;
	return (tab[0]);
}

static int	ft_word(char **split, char const *str, char c, int tab[3])
{
	tab[1] = 0;
	tab[2] = 0;
	while (str[tab[2]] != '\0')
	{
		while (sep(str[tab[2]], c) == 0)
		{
			if (str[tab[2]] == '\0')
				return (0);
			tab[2]++;
		}
		while (sep(str[tab[2]], c) == 1)
		{
			tab[1] = tab[2];
			tab[2]++;
			while (sep(str[tab[2]], c) == 1)
				tab[2]++;
			tab[0] = ft_word_malloc(split, str, tab);
			if (tab[0] == -1)
				return (-1);
		}
		if (str[tab[2]] == '\0')
			return (0);
		tab[2]++;
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		tab[3];

	if (s == NULL || c == 0)
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	if (nb_word(s, c) == 0)
	{
		split = malloc(sizeof(split));
		split[0] = NULL;
		return (split);
	}
	if (!(split = malloc(sizeof(*split) * (nb_word(s, c) + 1))))
	{
		free(split);
		return (NULL);
	}
	if (ft_word(split, s, c, tab) == 0)
		return (split);
	free(split);
	return (NULL);
}
