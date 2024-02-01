/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:01 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/01 16:02:50 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	fill_stack(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (num_check(ac, av[i]) != -1 && av[i] \
				&& ((ft_atoi(av[i]) > INT_MIN) && (ft_atoi(av[i]) < INT_MAX)))
		{
			add_new(a, ft_atoi(av[i]));
			if (*a == NULL)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		exit(0);
	if (ac <= 2)
	{
		if (num_check(ac, av[1]) == -1)
			return (ft_error());
		exit(0);
	}
	if (fill_stack(ac, av, &a) == -1)
		return (ft_error());
	if (check_dup(av) == -1)
		return (ft_error());
	ft_operate(&a, &b);
	return (0);
}
