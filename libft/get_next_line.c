/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/31 16:38:39 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/26 17:52:30 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_next_line(char *str, char **line, size_t i, int *test)
{
	char		*tmp;

	if (str)
	{
		if (str[i])
		{
			while (str[i] != '\n' && str[i])
				i++;
			if (str[i] == '\n')
			{
				if (i == 0)
					*line = ft_strdup("");
				else
					*line = ft_substr(str, 0, i);
				tmp = ft_strdup(&str[i + 1]);
				str = ft_strcpy(str, tmp);
				free(tmp);
			}
			else
				ft_next_line_cut(i, line, str);
			return (*line);
		}
	}
	*test = 3;
	return (ft_strdup(""));
}

char		*ft_strjoin_f(char *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	j = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str = malloc(sizeof(char) * j)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int			ft_searchline(const char *s, int c)
{
	int			i;
	char		*s1;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_free(char **str, int fd)
{
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str[4096];
	int			test;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (read(fd, buf, 0) < 0))
		return (-1);
	if (!((str[fd] != NULL) && (((test = ft_searchline(str[fd], '\n'))) == 1)))
		while (((ret = read(fd, buf, BUFFER_SIZE)) != 0))
		{
			if (ret < 0)
				return (-1);
			if (str[fd] == NULL)
				if (!(str[fd] = ft_strdup("")))
					return (-1);
			buf[ret] = '\0';
			if (!(str[fd] = ft_strjoin_f(str[fd], buf)))
				return (-1);
			if ((test = (ft_searchline(buf, '\n'))) == 1)
				break ;
		}
	if (((*line = ft_next_line(str[fd], line, 0, &test)) == NULL)
			|| (test == 0 && ret != BUFFER_SIZE) || test == 3)
		return (ft_free(str, fd));
	return (1);
}
