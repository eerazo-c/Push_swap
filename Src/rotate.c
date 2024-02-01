/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:59:01 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 16:56:58 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	if (write(1, "ra\n", 3) < 0)
	{
		ft_free(a);
		ft_error();
	}
}

void	rb(t_stack **b)
{
	rotate(b);
	if (write(1, "rb\n", 3) < 0)
	{
		ft_free(b);
		ft_error();
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	if (write(1, "rr\n", 3) < 0)
	{
		ft_free(a);
		ft_free(b);
		ft_error();
	}
}
