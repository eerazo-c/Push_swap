/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:02:37 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/01 13:04:06 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	add_new(t_stack **a, int content)
{
	t_stack	*new;
	t_stack	*aux;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		aux = *a;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

int	lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst != NULL)
	{
		count++;
		lst = lst-> next;
	}
	return (count);
}

int	ft_limit_check(long nb, t_stack **a)
{
	if (!(nb <= INT_MAX && nb >= INT_MIN))
	{
		ft_free(a);
		ft_error();
	}
	return (nb);
}

t_stack	*ft_lastnode(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (temp == NULL)
		return (temp);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}
