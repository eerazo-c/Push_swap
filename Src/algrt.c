/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algrt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:23:26 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 17:16:36 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

static t_stack	*get_next(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && \
					(!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_index_stack(t_stack **stack)
{
	t_stack	*minimizator;
	int		index2;

	index2 = 0;
	minimizator = get_next(stack);
	while (minimizator)
	{
		minimizator->index = index2++;
		minimizator = get_next(stack);
	}
}

void	ft_radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
