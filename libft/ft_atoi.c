/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:33:20 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 14:15:37 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int np;
	int nb;

	nb = 0;
	i = 0;
	np = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
			|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			np++;
		i++;
	}
	while (!((str[i] < '0') || (str[i] > '9')))
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	if (np % 2 == 1)
		return (-nb);
	return (nb);
}
