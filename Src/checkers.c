/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:09:46 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/07 17:32:38 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	check_dup(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (av[i] != NULL)
	{
		k = i + 1;
		while (av[k] != NULL)
		{
			j = 0;
			while (av[i][j] && av[k][j] && av[i][j] == av[k][j])
				j++;
			if (!av[i][j] && !av[k][j])
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}

int	num_check(int ac, char *av)
{
	int	i;

	(void)ac;
	i = 0;
	if ((av[i] == '-') || (av[i] == '+'))
		i++;
	if (av[i] == '\0')
		return (-1);
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	write (1, "\e[0;31mError\e[0m\n", 17);
	exit(1);
	return (-1);
}

void	ft_free(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
}
