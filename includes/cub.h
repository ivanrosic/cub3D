/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivanrosic <ivanrosic@student.le-101>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/26 12:34:49 by ivanrosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/10/12 01:42:01 by user42      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
#include "../libft/libft.h"

typedef struct	s_parse
{	
	char *str;
}				t_parse;


int		ft_parse(int ac, char **av, t_parse *parse);
void	ft_init_struct(t_parse *parse);
int		ft_open(char **av, t_parse *parse);
char	*ft_strjoin_f(char *s1, char const *s2);

#endif
