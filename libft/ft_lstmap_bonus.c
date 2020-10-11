/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 08:48:24 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 15:24:05 by ivarosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *list;

	if (f == NULL || lst == NULL)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&new, *del);
		return (NULL);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(list = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, *del);
			return (NULL);
		}
		ft_lstadd_back(&new, list);
		lst = lst->next;
	}
	return (new);
}
