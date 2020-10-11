/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:36:22 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:13:20 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long	ft_len(long n)
{
	long		i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

long	ft_power(long nb, long power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

char	*ft_itoa(int n)
{
	char	*nb;
	long	i;
	long	len;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_len(nbr) + 1;
	if (!(nb = malloc(sizeof(*nb) * (ft_len(nbr) + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nb[i++] = '-';
		nbr = -nbr;
		len--;
	}
	while (--len)
	{
		nb[i++] = (nbr / (ft_power(10, len - 1))) + 48;
		nbr = (nbr - (nbr / (ft_power(10, len - 1))) * ft_power(10, len - 1));
	}
	nb[i] = '\0';
	return (nb);
}
