/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:25:26 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 16:16:06 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}