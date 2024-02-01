/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:10:33 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 16:53:08 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	rev_rot(t_stack **stack)
{
	t_stack	*first;
	t_stack	*seco;
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	seco = *stack;
	temp = NULL;
	while (first->next != NULL)
	{
		temp = first;
		first = first->next;
	}
	temp->next = NULL;
	first->next = seco;
	*stack = first;
}

void	rra(t_stack **a)
{
	rev_rot(a);
	if (write(1, "rra\n", 4) < 0)
	{
		ft_free(a);
		ft_error();
	}
}

void	rrb(t_stack **b)
{
	rev_rot(b);
	if (write(1, "rrb\n", 4) < 0)
	{
		ft_free(b);
		ft_error();
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rot(a);
	rev_rot(b);
	if (write(1, "rrr\n", 4) < 0)
	{
		ft_free(a);
		ft_free(b);
		ft_error();
	}
}
