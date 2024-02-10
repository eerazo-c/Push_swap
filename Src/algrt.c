/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algrt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:23:26 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/08 20:14:34 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

static int	get_index(t_stack **stack, int num)
{
	t_stack	*head;
	int		has_min;

	head = *stack;
	has_min = 0;
	if (head)
	{
		while (head)
		{
			if (head->content < num)
				has_min++;
			head = head->next;
		}
	}
	return (has_min);
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
	minimizator = *stack;
	while (minimizator)
	{
		minimizator->index = get_index(stack, minimizator->content);
		minimizator = minimizator->next;
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
