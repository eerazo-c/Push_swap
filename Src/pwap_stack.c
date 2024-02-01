/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:49 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 16:41:18 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	if (*stack_b == NULL)
		return ;
	temp_b = *stack_b;
	*stack_b = temp_b->next;
	temp_b->next = *stack_a;
	*stack_a = temp_b;
	if (write(1, "pa\n", 3) < 0)
	{
		ft_free(stack_a);
		ft_free(stack_b);
		ft_error();
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	if (*stack_a == NULL)
		return ;
	temp_a = *stack_a;
	*stack_a = temp_a->next;
	temp_a->next = *stack_b;
	*stack_b = temp_a;
	if (write(1, "pb\n", 3) < 0)
	{
		ft_free (stack_a);
		ft_free(stack_b);
		ft_error();
	}
}
