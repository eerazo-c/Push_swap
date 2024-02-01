/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:54:35 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/01 12:19:05 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	ft_sort5(t_stack **a, t_stack **b)
{
	if (lstsize(*a) == 5 && ft_status_sort(*a) == 1)
	{
		ft_putmin_top(a);
		pb(a, b);
		ft_sort4(a, b);
		pa(a, b);
	}
}

int	ft_sort3_cases(t_stack **a)
{
	t_stack	*lastnode;
	t_stack	*middlenode;

	lastnode = ft_lastnode(*a);
	middlenode = (*a)->next;
	if ((*a)->content < lastnode->content)
	{
		if (middlenode->content < lastnode->content)
			return (1);
		return (3);
	}
	else
	{
		if ((middlenode->content > lastnode->content)
			&& middlenode->content < (*a)->content)
			return (2);
		else if ((middlenode->content > lastnode->content)
			&& middlenode->content > (*a)->content)
			return (4);
		else
			return (5);
	}
}

int	ft_min_locator(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		min_pos;
	int		min_value;

	min_value = (*stack)->content;
	temp = (*stack);
	min_pos = 0;
	i = 0;
	while (temp->next != NULL)
	{
		if (temp->content < min_value)
		{
			min_value = temp->content;
			min_pos = i;
		}
		i++;
		temp = temp->next;
	}
	if (temp->content < min_value)
	{
		min_pos = i;
		min_value = temp->content;
	}
	return (min_pos);
}

void	ft_putmin_top(t_stack **a)
{
	int	min_pos;
	int	go_up;
	int	go_down;
	int	size;

	min_pos = ft_min_locator(a);
	size = lstsize(*a);
	go_up = min_pos;
	go_down = size - min_pos;
	if (go_up <= go_down)
	{
		while (go_up > 0)
		{
			ra(a);
			go_up--;
		}
	}
	else if (go_down < go_up)
	{
		while (go_down > 0)
		{
			rra(a);
			go_down--;
		}
	}
}
