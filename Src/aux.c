/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:52 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/08 20:10:13 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	ft_operate(t_stack **a, t_stack **b)
{
	if (ft_status_sort(*a) == 0)
	{
		ft_free(a);
		exit(0);
	}
	if (lstsize(*a) == 2)
		ft_sort2(a);
	else if (lstsize(*a) == 3)
		ft_sort3(a);
	else if (lstsize(*a) == 4)
		ft_sort4(a, b);
	else if (lstsize(*a) <= 5)
		ft_sort5(a, b);
	else if (lstsize(*a) > 5)
		ft_radix_sort(a, b);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
	return (0);
}

int	ft_status_sort(t_stack *a)
{
	int	rslt;

	rslt = 0;
	while (a->next && rslt == 0)
	{
		if (a->content > a->next->content)
			rslt = 1;
		a = a->next;
	}
	return (rslt);
}

void	ft_sort2(t_stack **a)
{
	if (lstsize(*a) == 2 && ft_status_sort(*a) == 1)
		sa(a);
	else
		ft_error();
}

void	ft_sort3(t_stack **a)
{
	if (lstsize(*a) == 3 && ft_status_sort(*a) == 1)
	{
		if (ft_sort3_cases(a) == 1)
			sa(a);
		else if (ft_sort3_cases(a) == 2)
		{
			sa(a);
			rra(a);
		}
		else if (ft_sort3_cases(a) == 3)
		{
			sa(a);
			ra(a);
		}
		else if (ft_sort3_cases(a) == 4)
			rra(a);
		else if (ft_sort3_cases(a) == 5)
			ra(a);
	}
	else
		ft_error();
}

void	ft_sort4(t_stack **a, t_stack **b)
{
	if (lstsize(*a) == 4 && ft_status_sort(*a) == 1)
	{
		ft_putmin_top(a);
		if (ft_status_sort(*a) == 0)
			return ;
		pb(a, b);
		ft_sort3(a);
		pa(a, b);
	}
}
