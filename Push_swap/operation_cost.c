/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:17:40 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:27:18 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_costa(t_ps **a, int costa)
{
	while (costa > 0)
	{
		print_rotate_a(a);
		costa--;
	}
	while (costa < 0)
	{
		print_reverse_rotate_a(a);
		costa++;
	}	
}

void	operation_costb(t_ps **b, int costb)
{
	while (costb > 0)
	{
		print_rotate_b(b);
		costb--;
	}
	while (costb < 0)
	{
		print_reverse_rotate_b(b);
		costb++;
	}	
}

void	operation_cost(t_ps **a, t_ps **b, int costa, int costb)
{
	while (costa > 0 && costb > 0)
	{
		rotate_a_b(a, b);
		costa--;
		costb--;
	}
	while (costa < 0 && costb < 0)
	{
		reverse_rotate_a_b(a, b);
		costa++;
		costb++;
	}
	operation_costa(a, costa);
	operation_costb(b, costb);
	push_a(a, b);
}
