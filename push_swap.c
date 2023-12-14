/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:01 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/12/14 17:30:14 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int start_stack(t_stack **stack, int size, char**argv)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (number_valid(av[i] == -1 && argv[i][0] ))
	}
}

int main (int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc > 0)
	{
		if (start_stack_a(&a, argc, argv) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_order_stack(&a, &b, argc);
	}
	ft_free(&a);
	return (0);
}
