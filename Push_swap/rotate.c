/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:11:19 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:28:12 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*a == NULL)
		return ;
	tmp = *a;
	temp = tmp->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	(*a)->next = NULL;
	tmp->next = *a;
	*a = temp;
}

void	print_rotate_a(t_ps **a)
{
	rotate_a(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*b == NULL)
		return ;
	tmp = *b;
	temp = tmp->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	(*b)->next = NULL;
	tmp->next = *b;
	*b = temp;
}

void	print_rotate_b(t_ps **b)
{
	rotate_b(b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_ps **a, t_ps **b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
}
