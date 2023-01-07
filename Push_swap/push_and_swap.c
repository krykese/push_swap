/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:28:57 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/04 11:58:54 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ps **a, t_ps **b)
{
	t_ps	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	if ((*b)->next == NULL)
		*b = NULL;
	else
		*b = temp->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_ps **a, t_ps **b)
{
	t_ps	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	if ((*a)->next == NULL)
		a = NULL;
	else
		*a = temp->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	swap_a(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*a == NULL)
		return ;
	tmp = *a;
	temp = (*a)->next;
	tmp->next = temp->next;
	temp->next = tmp;
	*a = temp;
	tmp = temp->next;
	write(1, "sa\n", 3);
}

void	swap_b(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*b == NULL)
		return ;
	tmp = *b;
	temp = (*b)->next;
	tmp->next = temp->next;
	temp->next = tmp;
	*b = temp;
	tmp = temp->next;
	write(1, "sb\n", 3);
}

void	swap_a_b(t_ps **a, t_ps **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
