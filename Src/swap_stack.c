/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:57:18 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 20:07:53 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	ft_moves(t_stack **stack)
{
	t_stack	*first;
	t_stack	*seco;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	seco = (*stack)->next;
	*stack = seco;
	first->next = seco->next;
	seco->next = first;
}

void	sa(t_stack **a)
{
	if (*a == NULL)
		return ;
	ft_moves(a);
	if (write(1, "sa\n", 3) < 0)
	{
		ft_free(a);
		ft_error();
	}
}

void	sb(t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_moves(b);
	if (write(1, "sb\n", 3) < 0)
	{
		ft_free(b);
		ft_error();
	}
}

void	ss(t_stack **a, t_stack **b)
{
	ft_moves(a);
	ft_moves(b);
	if (write(1, "ss\n", 3) < 0)
	{
		ft_free(a);
		ft_free(b);
		ft_error();
	}
}
