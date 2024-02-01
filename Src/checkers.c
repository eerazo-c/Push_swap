/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:09:46 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/01 14:47:23 by eerazo-c         ###   ########.fr       */
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

	if (ac < 2)
		return (-1);
	i = 0;
	if ((av[i] == '-') || (av[i] == '+'))
		i++;
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
	write (1, "Error\n", 6);
	return (-1);
}

void	ft_free(t_stack **a)
{
	t_stack	*new;
	t_stack	*aux;
	t_stack	*p;

	if (*a == NULL)
		return ;
	new = *a;
	p = NULL;
	while (new != NULL)
	{
		p = aux;
		aux = new;
		new = new->next;
	}
	free(aux);
	if (p != NULL)
		p->next = NULL;
	*a = NULL;
	ft_free(a);
}
