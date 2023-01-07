/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:11:15 by qcosta            #+#    #+#             */
/*   Updated: 2022/10/06 16:27:36 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*a == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	temp = tmp->next;
	temp->next = *a;
	*a = temp;
	tmp->next = NULL;
}

void	print_reverse_rotate_a(t_ps **a)
{
	reverse_rotate_a(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*temp;

	if (*b == NULL)
		return ;
	tmp = *b;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	temp = tmp->next;
	temp->next = *b;
	*b = temp;
	tmp->next = NULL;
}

void	print_reverse_rotate_b(t_ps **b)
{
	reverse_rotate_b(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_ps **a, t_ps **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	write(1, "rrr\n", 4);
}
