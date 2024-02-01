/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:23 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/01 14:40:25 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
}						t_stack;

//prototipo funciones

int		fill_stack(int ac, char **av, t_stack **a);
int		num_check(int ac, char *av);
int		is_dup(const char *s1, const char *s2);
int		check_dup(char **av);
int		ft_error(void);
void	ft_free(t_stack **a);
int		ft_limit_check(long nb, t_stack **a);
int		lstsize(t_stack *lst);
t_stack	*ft_lastnode(t_stack *lst);

//listas && movimientos
void	add_new(t_stack **a, int content);
void	show_stack(t_stack *a);

void	ft_moves(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rot(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//algrt
void	ft_index_stack(t_stack **stack);
void	ft_radix_sort(t_stack **a, t_stack **b);

int		ft_operate(t_stack **a, t_stack **b);
int		ft_status_sort(t_stack *a);
void	ft_sort2(t_stack **a);
void	ft_sort3(t_stack **a);
void	ft_sort4(t_stack **a, t_stack **b);
void	ft_sort5(t_stack **a, t_stack **b);
int		ft_sort3_cases(t_stack **a);
int		ft_min_locator(t_stack **stack);
void	ft_putmin_top(t_stack **a);

#endif
