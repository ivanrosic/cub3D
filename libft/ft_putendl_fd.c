/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 10:45:00 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 15:14:28 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
